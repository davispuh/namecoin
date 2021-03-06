<<<<<<< HEAD
// Copyright (c) 2011-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "transactiondesc.h"

#include "bitcoinunits.h"
#include "guiutil.h"

#include "base58.h"
#include "db.h"
#include "main.h"
#include "paymentserver.h"
#include "transactionrecord.h"
#include "ui_interface.h"
#include "wallet.h"

#include <stdint.h>
=======
#include "transactiondesc.h"

#include "guiutil.h"
#include "bitcoinunits.h"
#include "../headers.h"
#include "../main.h"
#include "../wallet.h"
#include "../db.h"
#include "ui_interface.h"
#include "../base58.h"

>>>>>>> Committing original src/qt
#include <string>

QString TransactionDesc::FormatTxStatus(const CWalletTx& wtx)
{
<<<<<<< HEAD
    if (!IsFinalTx(wtx, chainActive.Height() + 1))
    {
        if (wtx.nLockTime < LOCKTIME_THRESHOLD)
            return tr("Open for %n more block(s)", "", wtx.nLockTime - chainActive.Height());
=======
    if (!wtx.IsFinal())
    {
        if (wtx.nLockTime < LOCKTIME_THRESHOLD)
            return tr("Open for %n more block(s)", "", wtx.nLockTime - nBestHeight + 1);
>>>>>>> Committing original src/qt
        else
            return tr("Open until %1").arg(GUIUtil::dateTimeStr(wtx.nLockTime));
    }
    else
    {
        int nDepth = wtx.GetDepthInMainChain();
<<<<<<< HEAD
        if (nDepth < 0)
            return tr("conflicted");
        else if (GetAdjustedTime() - wtx.nTimeReceived > 2 * 60 && wtx.GetRequestCount() == 0)
=======
        if (GetAdjustedTime() - wtx.nTimeReceived > 2 * 60 && wtx.GetRequestCount() == 0)
>>>>>>> Committing original src/qt
            return tr("%1/offline").arg(nDepth);
        else if (nDepth < 6)
            return tr("%1/unconfirmed").arg(nDepth);
        else
            return tr("%1 confirmations").arg(nDepth);
    }
}

<<<<<<< HEAD
QString TransactionDesc::toHTML(CWallet *wallet, CWalletTx &wtx, int vout, int unit)
=======
QString TransactionDesc::toHTML(CWallet *wallet, CWalletTx &wtx)
>>>>>>> Committing original src/qt
{
    QString strHTML;

    {
        LOCK(wallet->cs_wallet);
        strHTML.reserve(4000);
        strHTML += "<html><font face='verdana, arial, helvetica, sans-serif'>";

<<<<<<< HEAD
        int64_t nTime = wtx.GetTxTime();
        int64_t nCredit = wtx.GetCredit();
        int64_t nDebit = wtx.GetDebit();
        int64_t nNet = nCredit - nDebit;
=======
        int64 nTime = wtx.GetTxTime();
        int64 nCredit = wtx.GetCredit();
        int64 nDebit = wtx.GetDebit();
        int64 nNet = nCredit - nDebit;
>>>>>>> Committing original src/qt

        strHTML += "<b>" + tr("Status") + ":</b> " + FormatTxStatus(wtx);
        int nRequests = wtx.GetRequestCount();
        if (nRequests != -1)
        {
            if (nRequests == 0)
                strHTML += tr(", has not been successfully broadcast yet");
            else if (nRequests > 0)
                strHTML += tr(", broadcast through %n node(s)", "", nRequests);
        }
        strHTML += "<br>";

        strHTML += "<b>" + tr("Date") + ":</b> " + (nTime ? GUIUtil::dateTimeStr(nTime) : "") + "<br>";

        //
        // From
        //
        if (wtx.IsCoinBase())
        {
            strHTML += "<b>" + tr("Source") + ":</b> " + tr("Generated") + "<br>";
        }
        else if (wtx.mapValue.count("from") && !wtx.mapValue["from"].empty())
        {
            // Online transaction
            strHTML += "<b>" + tr("From") + ":</b> " + GUIUtil::HtmlEscape(wtx.mapValue["from"]) + "<br>";
        }
        else
        {
            // Offline transaction
            if (nNet > 0)
            {
                // Credit
                BOOST_FOREACH(const CTxOut& txout, wtx.vout)
                {
                    if (wallet->IsMine(txout))
                    {
                        CTxDestination address;
                        if (ExtractDestination(txout.scriptPubKey, address) && IsMine(*wallet, address))
                        {
                            if (wallet->mapAddressBook.count(address))
                            {
                                strHTML += "<b>" + tr("From") + ":</b> " + tr("unknown") + "<br>";
                                strHTML += "<b>" + tr("To") + ":</b> ";
                                strHTML += GUIUtil::HtmlEscape(CBitcoinAddress(address).ToString());
<<<<<<< HEAD
                                if (!wallet->mapAddressBook[address].name.empty())
                                    strHTML += " (" + tr("own address") + ", " + tr("label") + ": " + GUIUtil::HtmlEscape(wallet->mapAddressBook[address].name) + ")";
=======
                                if (!wallet->mapAddressBook[address].empty())
                                    strHTML += " (" + tr("own address") + ", " + tr("label") + ": " + GUIUtil::HtmlEscape(wallet->mapAddressBook[address]) + ")";
>>>>>>> Committing original src/qt
                                else
                                    strHTML += " (" + tr("own address") + ")";
                                strHTML += "<br>";
                            }
                        }
                        break;
                    }
                }
            }
        }

        //
        // To
        //
        if (wtx.mapValue.count("to") && !wtx.mapValue["to"].empty())
        {
            // Online transaction
            std::string strAddress = wtx.mapValue["to"];
            strHTML += "<b>" + tr("To") + ":</b> ";
            CTxDestination dest = CBitcoinAddress(strAddress).Get();
<<<<<<< HEAD
            if (wallet->mapAddressBook.count(dest) && !wallet->mapAddressBook[dest].name.empty())
                strHTML += GUIUtil::HtmlEscape(wallet->mapAddressBook[dest].name) + " ";
=======
            if (wallet->mapAddressBook.count(dest) && !wallet->mapAddressBook[dest].empty())
                strHTML += GUIUtil::HtmlEscape(wallet->mapAddressBook[dest]) + " ";
>>>>>>> Committing original src/qt
            strHTML += GUIUtil::HtmlEscape(strAddress) + "<br>";
        }

        //
        // Amount
        //
        if (wtx.IsCoinBase() && nCredit == 0)
        {
            //
            // Coinbase
            //
<<<<<<< HEAD
            int64_t nUnmatured = 0;
=======
            int64 nUnmatured = 0;
>>>>>>> Committing original src/qt
            BOOST_FOREACH(const CTxOut& txout, wtx.vout)
                nUnmatured += wallet->GetCredit(txout);
            strHTML += "<b>" + tr("Credit") + ":</b> ";
            if (wtx.IsInMainChain())
<<<<<<< HEAD
                strHTML += BitcoinUnits::formatWithUnit(unit, nUnmatured)+ " (" + tr("matures in %n more block(s)", "", wtx.GetBlocksToMaturity()) + ")";
=======
                strHTML += BitcoinUnits::formatWithUnit(BitcoinUnits::BTC, nUnmatured)+ " (" + tr("matures in %n more block(s)", "", wtx.GetBlocksToMaturity()) + ")";
>>>>>>> Committing original src/qt
            else
                strHTML += "(" + tr("not accepted") + ")";
            strHTML += "<br>";
        }
        else if (nNet > 0)
        {
            //
            // Credit
            //
<<<<<<< HEAD
            strHTML += "<b>" + tr("Credit") + ":</b> " + BitcoinUnits::formatWithUnit(unit, nNet) + "<br>";
=======
            strHTML += "<b>" + tr("Credit") + ":</b> " + BitcoinUnits::formatWithUnit(BitcoinUnits::BTC, nNet) + "<br>";
>>>>>>> Committing original src/qt
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

            if (fAllFromMe)
            {
                //
                // Debit
                //
                int64 nTxFee = nDebit - (wtx.GetValueOut() - nCarriedOverCoin);
                BOOST_FOREACH(const CTxOut& txout, wtx.vout)
                {
                    if (wallet->IsMine(txout))
                        continue;

                    int64 nValue = txout.nValue;

                    if (!wtx.mapValue.count("to") || wtx.mapValue["to"].empty())
                    {
                        // Offline transaction
                        CTxDestination address;
                        if (ExtractDestination(txout.scriptPubKey, address))
                        {
                            strHTML += "<b>" + tr("To") + ":</b> ";
<<<<<<< HEAD
                            if (wallet->mapAddressBook.count(address) && !wallet->mapAddressBook[address].name.empty())
                                strHTML += GUIUtil::HtmlEscape(wallet->mapAddressBook[address].name) + " ";
=======
                            if (wallet->mapAddressBook.count(address) && !wallet->mapAddressBook[address].empty())
                                strHTML += GUIUtil::HtmlEscape(wallet->mapAddressBook[address]) + " ";
>>>>>>> Committing original src/qt
                            strHTML += GUIUtil::HtmlEscape(CBitcoinAddress(address).ToString());
                            strHTML += "<br>";
                        }
                        else if (hooks->ExtractAddress(txout.scriptPubKey, address))
                        {
                            strHTML += "<b>" + tr("Name operation") + ":</b> " + GUIUtil::HtmlEscape(address) + "<br>";

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

                        // Carried over coin can be used to pay fee, if it the required
                        // amount was reserved in OP_NAME_NEW
                        if (nCarriedOverCoin > 0)
                        {
                            if (nTxFee >= nCarriedOverCoin)
                            {
                                nTxFee -= nCarriedOverCoin;
                                nCarriedOverCoin = 0;
                            }
                            else
                            {
                                nCarriedOverCoin -= nTxFee;
                                nTxFee = 0;
                            }
                        }


                    }

<<<<<<< HEAD
<<<<<<< HEAD
                    strHTML += "<b>" + tr("Debit") + ":</b> " + BitcoinUnits::formatWithUnit(unit, -txout.nValue) + "<br>";
=======
                    strHTML += "<b>" + tr("Debit") + ":</b> " + BitcoinUnits::formatWithUnit(BitcoinUnits::BTC, -txout.nValue) + "<br>";
>>>>>>> Committing original src/qt
=======
                    strHTML += "<b>" + tr("Debit") + ":</b> " + BitcoinUnits::formatWithUnit(BitcoinUnits::BTC, -nValue) + "<br>";
>>>>>>> listtransactions fix, various GUI fixes.
                }

                if (fAllToMe)
                {
                    // Payment to self
<<<<<<< HEAD
                    int64_t nChange = wtx.GetChange();
                    int64_t nValue = nCredit - nChange;
                    strHTML += "<b>" + tr("Debit") + ":</b> " + BitcoinUnits::formatWithUnit(unit, -nValue) + "<br>";
                    strHTML += "<b>" + tr("Credit") + ":</b> " + BitcoinUnits::formatWithUnit(unit, nValue) + "<br>";
                }

                int64_t nTxFee = nDebit - wtx.GetValueOut();
                if (nTxFee > 0)
                    strHTML += "<b>" + tr("Transaction fee") + ":</b> " + BitcoinUnits::formatWithUnit(unit, -nTxFee) + "<br>";
=======
                    int64 nChange = wtx.GetChange();
                    int64 nValue = nCredit - nChange;
                    strHTML += "<b>" + tr("Debit") + ":</b> " + BitcoinUnits::formatWithUnit(BitcoinUnits::BTC, -nValue) + "<br>";
                    strHTML += "<b>" + tr("Credit") + ":</b> " + BitcoinUnits::formatWithUnit(BitcoinUnits::BTC, nValue) + "<br>";
                }

                if (nTxFee > 0)
                    strHTML += "<b>" + tr("Transaction fee") + ":</b> " + BitcoinUnits::formatWithUnit(BitcoinUnits::BTC, -nTxFee) + "<br>";
>>>>>>> Committing original src/qt
            }
            else
            {
                //
                // Mixed debit transaction
                //
                BOOST_FOREACH(const CTxIn& txin, wtx.vin)
                    if (wallet->IsMine(txin))
<<<<<<< HEAD
                        strHTML += "<b>" + tr("Debit") + ":</b> " + BitcoinUnits::formatWithUnit(unit, -wallet->GetDebit(txin)) + "<br>";
                BOOST_FOREACH(const CTxOut& txout, wtx.vout)
                    if (wallet->IsMine(txout))
                        strHTML += "<b>" + tr("Credit") + ":</b> " + BitcoinUnits::formatWithUnit(unit, wallet->GetCredit(txout)) + "<br>";
            }
        }

        strHTML += "<b>" + tr("Net amount") + ":</b> " + BitcoinUnits::formatWithUnit(unit, nNet, true) + "<br>";
=======
                        strHTML += "<b>" + tr("Debit") + ":</b> " + BitcoinUnits::formatWithUnit(BitcoinUnits::BTC, -wallet->GetDebit(txin)) + "<br>";
                BOOST_FOREACH(const CTxOut& txout, wtx.vout)
                    if (wallet->IsMine(txout))
                        strHTML += "<b>" + tr("Credit") + ":</b> " + BitcoinUnits::formatWithUnit(BitcoinUnits::BTC, wallet->GetCredit(txout)) + "<br>";
            }
        }

        strHTML += "<b>" + tr("Net amount") + ":</b> " + BitcoinUnits::formatWithUnit(BitcoinUnits::BTC, nNet, true) + "<br>";
>>>>>>> Committing original src/qt

        //
        // Message
        //
        if (wtx.mapValue.count("message") && !wtx.mapValue["message"].empty())
            strHTML += "<br><b>" + tr("Message") + ":</b><br>" + GUIUtil::HtmlEscape(wtx.mapValue["message"], true) + "<br>";
        if (wtx.mapValue.count("comment") && !wtx.mapValue["comment"].empty())
            strHTML += "<br><b>" + tr("Comment") + ":</b><br>" + GUIUtil::HtmlEscape(wtx.mapValue["comment"], true) + "<br>";

<<<<<<< HEAD
        strHTML += "<b>" + tr("Transaction ID") + ":</b> " + TransactionRecord::formatSubTxId(wtx.GetHash(), vout) + "<br>";

        // Message from normal bitcoin:URI (bitcoin:123...?message=example)
        foreach (const PAIRTYPE(string, string)& r, wtx.vOrderForm)
            if (r.first == "Message")
                strHTML += "<br><b>" + tr("Message") + ":</b><br>" + GUIUtil::HtmlEscape(r.second, true) + "<br>";

        //
        // PaymentRequest info:
        //
        foreach (const PAIRTYPE(string, string)& r, wtx.vOrderForm)
        {
            if (r.first == "PaymentRequest")
            {
                PaymentRequestPlus req;
                req.parse(QByteArray::fromRawData(r.second.data(), r.second.size()));
                QString merchant;
                if (req.getMerchant(PaymentServer::getCertStore(), merchant))
                    strHTML += "<b>" + tr("Merchant") + ":</b> " + GUIUtil::HtmlEscape(merchant) + "<br>";
            }
        }

        if (wtx.IsCoinBase())
        {
            quint32 numBlocksToMaturity = COINBASE_MATURITY +  1;
            strHTML += "<br>" + tr("Generated coins must mature %1 blocks before they can be spent. When you generated this block, it was broadcast to the network to be added to the block chain. If it fails to get into the chain, its state will change to \"not accepted\" and it won't be spendable. This may occasionally happen if another node generates a block within a few seconds of yours.").arg(QString::number(numBlocksToMaturity)) + "<br>";
        }
=======
        strHTML += "<b>" + tr("Transaction ID") + ":</b> " + wtx.GetHash().ToString().c_str() + "<br>";

        if (wtx.IsCoinBase())
            strHTML += "<br>" + tr("Generated coins must mature 120 blocks before they can be spent. When you generated this block, it was broadcast to the network to be added to the block chain. If it fails to get into the chain, its state will change to \"not accepted\" and it won't be spendable. This may occasionally happen if another node generates a block within a few seconds of yours.") + "<br>";
>>>>>>> Committing original src/qt

        //
        // Debug view
        //
        if (fDebug)
        {
            strHTML += "<hr><br>" + tr("Debug information") + "<br><br>";
            BOOST_FOREACH(const CTxIn& txin, wtx.vin)
                if(wallet->IsMine(txin))
<<<<<<< HEAD
                    strHTML += "<b>" + tr("Debit") + ":</b> " + BitcoinUnits::formatWithUnit(unit, -wallet->GetDebit(txin)) + "<br>";
            BOOST_FOREACH(const CTxOut& txout, wtx.vout)
                if(wallet->IsMine(txout))
                    strHTML += "<b>" + tr("Credit") + ":</b> " + BitcoinUnits::formatWithUnit(unit, wallet->GetCredit(txout)) + "<br>";
=======
                    strHTML += "<b>" + tr("Debit") + ":</b> " + BitcoinUnits::formatWithUnit(BitcoinUnits::BTC, -wallet->GetDebit(txin)) + "<br>";
            BOOST_FOREACH(const CTxOut& txout, wtx.vout)
                if(wallet->IsMine(txout))
                    strHTML += "<b>" + tr("Credit") + ":</b> " + BitcoinUnits::formatWithUnit(BitcoinUnits::BTC, wallet->GetCredit(txout)) + "<br>";
>>>>>>> Committing original src/qt

            strHTML += "<br><b>" + tr("Transaction") + ":</b><br>";
            strHTML += GUIUtil::HtmlEscape(wtx.ToString(), true);

            strHTML += "<br><b>" + tr("Inputs") + ":</b>";
            
            strHTML += "<i>Not implemented...</i>";
            /*strHTML += "<ul>";

            {
                LOCK(wallet->cs_wallet);
                BOOST_FOREACH(const CTxIn& txin, wtx.vin)
                {
                    COutPoint prevout = txin.prevout;

                    CCoins prev;
                    if(pcoinsTip->GetCoins(prevout.hash, prev))
                    {
                        if (prevout.n < prev.vout.size())
                        {
                            strHTML += "<li>";
                            const CTxOut &vout = prev.vout[prevout.n];
                            CTxDestination address;
                            if (ExtractDestination(vout.scriptPubKey, address))
                            {
<<<<<<< HEAD
                                if (wallet->mapAddressBook.count(address) && !wallet->mapAddressBook[address].name.empty())
                                    strHTML += GUIUtil::HtmlEscape(wallet->mapAddressBook[address].name) + " ";
                                strHTML += QString::fromStdString(CBitcoinAddress(address).ToString());
                            }
                            strHTML = strHTML + " " + tr("Amount") + "=" + BitcoinUnits::formatWithUnit(unit, vout.nValue);
=======
                                if (wallet->mapAddressBook.count(address) && !wallet->mapAddressBook[address].empty())
                                    strHTML += GUIUtil::HtmlEscape(wallet->mapAddressBook[address]) + " ";
                                strHTML += QString::fromStdString(CBitcoinAddress(address).ToString());
                            }
                            strHTML = strHTML + " " + tr("Amount") + "=" + BitcoinUnits::formatWithUnit(BitcoinUnits::BTC, vout.nValue);
>>>>>>> Committing original src/qt
                            strHTML = strHTML + " IsMine=" + (wallet->IsMine(vout) ? tr("true") : tr("false")) + "</li>";
                        }
                    }
                }
            }*/

            strHTML += "</ul>";
        }

        strHTML += "</font></html>";
    }
    return strHTML;
}
