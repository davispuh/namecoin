<<<<<<< HEAD
// Copyright (c) 2011-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "transactionrecord.h"

#include "base58.h"
#include "wallet.h"

#include <stdint.h>
=======
#include "transactionrecord.h"

<<<<<<< HEAD
#include "wallet.h"
#include "base58.h"
>>>>>>> Committing original src/qt
=======
#include "../headers.h"
#include "../wallet.h"
#include "../base58.h"
#include "ui_interface.h"
>>>>>>> Commiting my updates that turn namecoind into namecoin-qt.

/* Return positive answer if transaction should be shown in list.
 */
bool TransactionRecord::showTransaction(const CWalletTx &wtx)
{
    if (wtx.IsCoinBase())
    {
        // Ensures we show generated coins / mined transactions at depth 1
        if (!wtx.IsInMainChain())
        {
            return false;
        }
    }
    return true;
}

/*
 * Decompose CWallet transaction to model transaction records.
 */
QList<TransactionRecord> TransactionRecord::decomposeTransaction(const CWallet *wallet, const CWalletTx &wtx)
{
    QList<TransactionRecord> parts;
<<<<<<< HEAD
    int64_t nTime = wtx.GetTxTime();
    int64_t nCredit = wtx.GetCredit(true);
    int64_t nDebit = wtx.GetDebit();
    int64_t nNet = nCredit - nDebit;
=======
    int64 nTime = wtx.GetTxTime();
    int64 nCredit = wtx.GetCredit(true);
    int64 nDebit = wtx.GetDebit();
    int64 nNet = nCredit - nDebit;
>>>>>>> Committing original src/qt
    uint256 hash = wtx.GetHash();
    std::map<std::string, std::string> mapValue = wtx.mapValue;

    if (nNet > 0 || wtx.IsCoinBase())
    {
        //
        // Credit
        //
        BOOST_FOREACH(const CTxOut& txout, wtx.vout)
        {
            if(wallet->IsMine(txout))
            {
                TransactionRecord sub(hash, nTime);
                std::string address;
                sub.idx = parts.size(); // sequence number
                sub.credit = txout.nValue;
                if (ExtractDestination(txout.scriptPubKey, address) && IsMine(*wallet, address))
                {
                    // Received by Bitcoin Address
                    sub.type = TransactionRecord::RecvWithAddress;
                    sub.address = CBitcoinAddress(address).ToString();
                }
                else
                {
                    // Received by IP connection (deprecated features), or a multisignature or other non-simple transaction
                    sub.type = TransactionRecord::RecvFromOther;
                    sub.address = mapValue["from"];
                }
                if (wtx.IsCoinBase())
                {
                    // Generated
                    sub.type = TransactionRecord::Generated;
                }

                parts.append(sub);
            }
        }
    }
    else
    {
        bool fAllFromMe = true;
        int64 nCarriedOverCoin = 0;
        BOOST_FOREACH(const CTxIn& txin, wtx.vin)
        {
            if (!wallet->IsMine(txin))
            {
                // Check whether transaction input is name_* operation - in this case consider it ours
                CTransaction txPrev;
                uint256 hash = 0;
                CTxDestination address;
                if (GetTransaction(txin.prevout.hash, txPrev, hash) &&
                        txin.prevout.n < txPrev.vout.size() &&
                        hooks->ExtractAddress(txPrev.vout[txin.prevout.n].scriptPubKey, address)
                   )
                {
                    // This is our name transaction
                    // Accumulate the coin carried from name_new, because it is not actually spent
                    nCarriedOverCoin += txPrev.vout[txin.prevout.n].nValue;
                }
                else
                {
                    fAllFromMe = false;
                    break;
                }
            }
        }
        
        bool fAllToMe = true;
        BOOST_FOREACH(const CTxOut& txout, wtx.vout)
            if (!wallet->IsMine(txout))
            {
                fAllToMe = false;
                break;
            }

        if (fAllFromMe && fAllToMe)
        {
            // Payment to self
<<<<<<< HEAD
            int64_t nChange = wtx.GetChange();
=======
            int64 nChange = wtx.GetChange();
>>>>>>> Committing original src/qt

            parts.append(TransactionRecord(hash, nTime, TransactionRecord::SendToSelf, "",
                            -(nDebit - nChange), nCredit - nChange));
        }
        else if (fAllFromMe)
        {
            //
            // Debit
            //
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
            int64_t nTxFee = nDebit - wtx.GetValueOut();
=======
            int64 nTxFee = nDebit - wtx.GetValueOut();
>>>>>>> Committing original src/qt
=======
            int64 nTxFee = nDebit - (wtx.GetValueOut() - nCarriedOverCoin);
>>>>>>> Added GUI tab for name_* commands. Version 0.3.60.
=======
            int64 nTxFee = nDebit - (wtx.GetValueOut() - nCarriedOverCoin);
>>>>>>> Added GUI tab for name_* commands. Version 0.3.60.

            for (unsigned int nOut = 0; nOut < wtx.vout.size(); nOut++)
            {
                const CTxOut& txout = wtx.vout[nOut];
                TransactionRecord sub(hash, nTime);
                sub.idx = parts.size();

                if(wallet->IsMine(txout))
                {
                    // Ignore parts sent to self, as this is usually the change
                    // from a transaction sent back to our own address.
                    continue;
                }

                int64 nValue = txout.nValue;
                
                std::string address;
                if (ExtractDestination(txout.scriptPubKey, address))
                {
                    // Sent to Bitcoin Address
                    sub.type = TransactionRecord::SendToAddress;
                    sub.address = CBitcoinAddress(address).ToString();
                }
                else if (hooks->ExtractAddress(txout.scriptPubKey, address))
                {
                    sub.type = TransactionRecord::NameOp;
                    sub.address = address;
                    
                    // Add carried coin (from name_new)
                    if (nCarriedOverCoin > 0)
                    {
                        // Note: we subtract nCarriedOverCoin equally from all name operations,
                        // until it becomes zero. It may fail for complex transactions, which
                        // update multiple names simultaneously (standard client never creates such transactions).
                        if (nValue >= nCarriedOverCoin)
                        {
                            nValue -= nCarriedOverCoin;
                            nCarriedOverCoin = 0;
                        }
                        else
                        {
                            nCarriedOverCoin -= nValue;
                            nValue = 0;
                        }
                    }
                }
                else
                {
                    // Sent to IP, or other non-address transaction like OP_EVAL
                    sub.type = TransactionRecord::SendToOther;
                    sub.address = mapValue["to"];
                }

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
                int64_t nValue = txout.nValue;
=======
                int64 nValue = txout.nValue;
>>>>>>> Committing original src/qt
=======
>>>>>>> Added GUI tab for name_* commands. Version 0.3.60.
=======
>>>>>>> Added GUI tab for name_* commands. Version 0.3.60.
                /* Add fee to first output */
                if (nTxFee > 0)
                {
                    nValue += nTxFee;
                    nTxFee = 0;
                }

                sub.debit = -nValue;

                parts.append(sub);
            }
        }
        else
        {
            //
            // Check for name transferring operation
            //
            BOOST_FOREACH(const CTxOut& txout, wtx.vout)
            {
                std::string address;
                // We do not check, if coin address belongs to us, assuming that the wallet can only contain
                // transactions involving us
                if (hooks->ExtractAddress(txout.scriptPubKey, address))
                    parts.append(TransactionRecord(hash, nTime, TransactionRecord::NameOp, address, 0, 0));
            }

            //
            // Mixed debit transaction, can't break down payees
            //
            if (parts.empty() || nNet != 0)
                parts.append(TransactionRecord(hash, nTime, TransactionRecord::Other, "", nNet, 0));
        }
    }

    return parts;
}

void TransactionRecord::updateStatus(const CWalletTx &wtx)
{
    // Determine transaction status

    // Find the block the tx is in
    CBlockIndex* pindex = NULL;
    std::map<uint256, CBlockIndex*>::iterator mi = mapBlockIndex.find(wtx.hashBlock);
    if (mi != mapBlockIndex.end())
        pindex = (*mi).second;

    // Sort order, unrecorded transactions sort to the top
    status.sortKey = strprintf("%010d-%01d-%010u-%03d",
        (pindex ? pindex->nHeight : std::numeric_limits<int>::max()),
        (wtx.IsCoinBase() ? 1 : 0),
        wtx.nTimeReceived,
        idx);
<<<<<<< HEAD
    status.confirmed = wtx.IsTrusted();
    status.depth = wtx.GetDepthInMainChain();
    status.cur_num_blocks = chainActive.Height();

    if (!IsFinalTx(wtx, chainActive.Height() + 1))
=======
    status.confirmed = wtx.IsConfirmed();
    status.depth = wtx.GetDepthInMainChain();
    status.cur_num_blocks = nBestHeight;

    if (!wtx.IsFinal())
>>>>>>> Committing original src/qt
    {
        if (wtx.nLockTime < LOCKTIME_THRESHOLD)
        {
            status.status = TransactionStatus::OpenUntilBlock;
<<<<<<< HEAD
            status.open_for = wtx.nLockTime - chainActive.Height();
=======
            status.open_for = wtx.nLockTime - nBestHeight + 1;
>>>>>>> Committing original src/qt
        }
        else
        {
            status.status = TransactionStatus::OpenUntilDate;
            status.open_for = wtx.nLockTime;
        }
    }
    else
    {
<<<<<<< HEAD
        if (status.depth < 0)
        {
            status.status = TransactionStatus::Conflicted;
        }
        else if (GetAdjustedTime() - wtx.nTimeReceived > 2 * 60 && wtx.GetRequestCount() == 0)
=======
        if (GetAdjustedTime() - wtx.nTimeReceived > 2 * 60 && wtx.GetRequestCount() == 0)
>>>>>>> Committing original src/qt
        {
            status.status = TransactionStatus::Offline;
        }
        else if (status.depth < NumConfirmations)
        {
            status.status = TransactionStatus::Unconfirmed;
        }
        else
        {
            status.status = TransactionStatus::HaveConfirmations;
        }
    }

    // For generated transactions, determine maturity
    if(type == TransactionRecord::Generated)
    {
<<<<<<< HEAD
        int64_t nCredit = wtx.GetCredit(true);
=======
        int64 nCredit = wtx.GetCredit(true);
>>>>>>> Committing original src/qt
        if (nCredit == 0)
        {
            status.maturity = TransactionStatus::Immature;

            if (wtx.IsInMainChain())
            {
                status.matures_in = wtx.GetBlocksToMaturity();

                // Check if the block was requested by anyone
                if (GetAdjustedTime() - wtx.nTimeReceived > 2 * 60 && wtx.GetRequestCount() == 0)
                    status.maturity = TransactionStatus::MaturesWarning;
            }
            else
            {
                status.maturity = TransactionStatus::NotAccepted;
            }
        }
        else
        {
            status.maturity = TransactionStatus::Mature;
        }
    }
}

bool TransactionRecord::statusUpdateNeeded()
{
<<<<<<< HEAD
    return status.cur_num_blocks != chainActive.Height();
}

QString TransactionRecord::getTxID() const
{
    return formatSubTxId(hash, idx);
}

QString TransactionRecord::formatSubTxId(const uint256 &hash, int vout)
{
    return QString::fromStdString(hash.ToString() + strprintf("-%03d", vout));
=======
    return status.cur_num_blocks != nBestHeight;
}

std::string TransactionRecord::getTxID()
{
    return hash.ToString() + strprintf("-%03d", idx);
>>>>>>> Committing original src/qt
}

