<<<<<<< HEAD
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

=======
/*
 * Qt4 bitcoin GUI.
 *
 * W.J. van der Laan 2011-2012
 * The Bitcoin Developers 2011-2013
 */
>>>>>>> Committing original src/qt
#ifndef WALLETVIEW_H
#define WALLETVIEW_H

#include <QStackedWidget>

class BitcoinGUI;
class ClientModel;
<<<<<<< HEAD
class OverviewPage;
class ReceiveCoinsDialog;
class SendCoinsDialog;
class SendCoinsRecipient;
class TransactionView;
class WalletModel;

QT_BEGIN_NAMESPACE
=======
class WalletModel;
class TransactionView;
class OverviewPage;
class AddressBookPage;
class SendCoinsDialog;
class SignVerifyMessageDialog;
class RPCConsole;

QT_BEGIN_NAMESPACE
class QLabel;
>>>>>>> Committing original src/qt
class QModelIndex;
QT_END_NAMESPACE

/*
  WalletView class. This class represents the view to a single wallet.
  It was added to support multiple wallet functionality. Each wallet gets its own WalletView instance.
  It communicates with both the client and the wallet models to give the user an up-to-date view of the
  current core state.
*/
class WalletView : public QStackedWidget
{
    Q_OBJECT

public:
<<<<<<< HEAD
    explicit WalletView(QWidget *parent);
=======
    explicit WalletView(QWidget *parent, BitcoinGUI *_gui);
>>>>>>> Committing original src/qt
    ~WalletView();

    void setBitcoinGUI(BitcoinGUI *gui);
    /** Set the client model.
        The client model represents the part of the core that communicates with the P2P network, and is wallet-agnostic.
    */
    void setClientModel(ClientModel *clientModel);
    /** Set the wallet model.
        The wallet model represents a bitcoin wallet, and offers access to the list of transactions, address book and sending
        functionality.
    */
    void setWalletModel(WalletModel *walletModel);

<<<<<<< HEAD
    bool handlePaymentRequest(const SendCoinsRecipient& recipient);
=======
    bool handleURI(const QString &uri);
>>>>>>> Committing original src/qt

    void showOutOfSyncWarning(bool fShow);

private:
<<<<<<< HEAD
=======
    BitcoinGUI *gui;
>>>>>>> Committing original src/qt
    ClientModel *clientModel;
    WalletModel *walletModel;

    OverviewPage *overviewPage;
    QWidget *transactionsPage;
<<<<<<< HEAD
    ReceiveCoinsDialog *receiveCoinsPage;
    SendCoinsDialog *sendCoinsPage;
=======
    AddressBookPage *addressBookPage;
    AddressBookPage *receiveCoinsPage;
    SendCoinsDialog *sendCoinsPage;
    SignVerifyMessageDialog *signVerifyMessageDialog;
>>>>>>> Committing original src/qt

    TransactionView *transactionView;

public slots:
    /** Switch to overview (home) page */
    void gotoOverviewPage();
    /** Switch to history (transactions) page */
    void gotoHistoryPage();
<<<<<<< HEAD
=======
    /** Switch to address book page */
    void gotoAddressBookPage();
>>>>>>> Committing original src/qt
    /** Switch to receive coins page */
    void gotoReceiveCoinsPage();
    /** Switch to send coins page */
    void gotoSendCoinsPage(QString addr = "");

    /** Show Sign/Verify Message dialog and switch to sign message tab */
    void gotoSignMessageTab(QString addr = "");
    /** Show Sign/Verify Message dialog and switch to verify message tab */
    void gotoVerifyMessageTab(QString addr = "");

    /** Show incoming transaction notification for new transactions.

        The new items are those between start and end inclusive, under the given parent item.
    */
<<<<<<< HEAD
    void processNewTransaction(const QModelIndex& parent, int start, int /*end*/);
=======
    void incomingTransaction(const QModelIndex& parent, int start, int /*end*/);
>>>>>>> Committing original src/qt
    /** Encrypt the wallet */
    void encryptWallet(bool status);
    /** Backup the wallet */
    void backupWallet();
    /** Change encrypted wallet passphrase */
    void changePassphrase();
    /** Ask for passphrase to unlock wallet temporarily */
    void unlockWallet();

<<<<<<< HEAD
    /** Show used sending addresses */
    void usedSendingAddresses();
    /** Show used receiving addresses */
    void usedReceivingAddresses();

    /** Re-emit encryption status signal */
    void updateEncryptionStatus();

signals:
    /** Signal that we want to show the main window */
    void showNormalIfMinimized();
    /**  Fired when a message should be reported to the user */
    void message(const QString &title, const QString &message, unsigned int style);
    /** Encryption status of wallet changed */
    void encryptionStatusChanged(int status);
    /** Notify that a new transaction appeared */
    void incomingTransaction(const QString& date, int unit, qint64 amount, const QString& type, const QString& address);
=======
    void setEncryptionStatus();
>>>>>>> Committing original src/qt
};

#endif // WALLETVIEW_H
