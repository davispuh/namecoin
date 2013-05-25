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
#ifndef WALLETFRAME_H
#define WALLETFRAME_H

#include <QFrame>
<<<<<<< HEAD
#include <QMap>

class BitcoinGUI;
class ClientModel;
class SendCoinsRecipient;
class WalletModel;
class WalletView;

QT_BEGIN_NAMESPACE
class QStackedWidget;
QT_END_NAMESPACE
=======

class BitcoinGUI;
class ClientModel;
class WalletModel;
class WalletStack;
>>>>>>> Committing original src/qt

class WalletFrame : public QFrame
{
    Q_OBJECT
<<<<<<< HEAD

public:
    explicit WalletFrame(BitcoinGUI *_gui = 0);
=======
public:
    explicit WalletFrame(BitcoinGUI *_gui);
>>>>>>> Committing original src/qt
    ~WalletFrame();

    void setClientModel(ClientModel *clientModel);

    bool addWallet(const QString& name, WalletModel *walletModel);
    bool setCurrentWallet(const QString& name);
<<<<<<< HEAD
    bool removeWallet(const QString &name);
    void removeAllWallets();

    bool handlePaymentRequest(const SendCoinsRecipient& recipient);
=======

    void removeAllWallets();

    bool handleURI(const QString &uri);
>>>>>>> Committing original src/qt

    void showOutOfSyncWarning(bool fShow);

private:
<<<<<<< HEAD
    QStackedWidget *walletStack;
    BitcoinGUI *gui;
    ClientModel *clientModel;
    QMap<QString, WalletView*> mapWalletViews;

    bool bOutOfSync;

    WalletView *currentWalletView();
=======
    BitcoinGUI *gui;
    ClientModel *clientModel;
    WalletStack *walletStack;
>>>>>>> Committing original src/qt

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
};

#endif // WALLETFRAME_H
=======
    /** Set the encryption status as shown in the UI.
     @param[in] status            current encryption status
     @see WalletModel::EncryptionStatus
     */
    void setEncryptionStatus();
};

#endif // WALLETFRAME_H
>>>>>>> Committing original src/qt
