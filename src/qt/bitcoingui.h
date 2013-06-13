<<<<<<< HEAD
// Copyright (c) 2011-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINGUI_H
#define BITCOINGUI_H

#if defined(HAVE_CONFIG_H)
#include "bitcoin-config.h"
#endif

#include <QMainWindow>
#include <QMap>
#include <QSystemTrayIcon>

class ClientModel;
class Notificator;
class RPCConsole;
class SendCoinsRecipient;
class WalletFrame;
class WalletModel;
=======
#ifndef BITCOINGUI_H
#define BITCOINGUI_H

#include <QMainWindow>
#include <QSystemTrayIcon>

class TransactionTableModel;
class ClientModel;
class WalletModel;
class TransactionView;
class OverviewPage;
class AddressBookPage;
class SendCoinsDialog;
class ManageNamesPage;
class SignVerifyMessageDialog;
class Notificator;
class RPCConsole;
>>>>>>> Committing original src/qt

QT_BEGIN_NAMESPACE
<<<<<<< HEAD
class QAction;
class QLabel;
class QProgressBar;
=======
class QLabel;
class QModelIndex;
class QProgressBar;
class QStackedWidget;
<<<<<<< HEAD
class QUrl;
class QListWidget;
class QPushButton;
class QAction;
>>>>>>> Committing original src/qt
=======
>>>>>>> Commiting my updates that turn namecoind into namecoin-qt.
QT_END_NAMESPACE

/**
  Bitcoin GUI main class. This class represents the main window of the Bitcoin UI. It communicates with both the client and
  wallet models to give the user an up-to-date view of the current core state.
*/
class BitcoinGUI : public QMainWindow
{
    Q_OBJECT

public:
<<<<<<< HEAD
    static const QString DEFAULT_WALLET;

<<<<<<< HEAD
    explicit BitcoinGUI(bool fIsTestnet = false, QWidget *parent = 0);
=======
=======
>>>>>>> Commiting my updates that turn namecoind into namecoin-qt.
    explicit BitcoinGUI(QWidget *parent = 0);
>>>>>>> Committing original src/qt
    ~BitcoinGUI();

    /** Set the client model.
        The client model represents the part of the core that communicates with the P2P network, and is wallet-agnostic.
    */
    void setClientModel(ClientModel *clientModel);
<<<<<<< HEAD

#ifdef ENABLE_WALLET
=======
>>>>>>> Committing original src/qt
    /** Set the wallet model.
        The wallet model represents a bitcoin wallet, and offers access to the list of transactions, address book and sending
        functionality.
    */
<<<<<<< HEAD
<<<<<<< HEAD
    bool addWallet(const QString& name, WalletModel *walletModel);
    bool setCurrentWallet(const QString& name);
    void removeAllWallets();
#endif
=======

    bool addWallet(const QString& name, WalletModel *walletModel);
    bool setCurrentWallet(const QString& name);

    void removeAllWallets();

    /** Used by WalletView to allow access to needed QActions */
    // Todo: Use Qt signals for these
    QAction * getOverviewAction() { return overviewAction; }
    QAction * getHistoryAction() { return historyAction; }
    QAction * getAddressBookAction() { return addressBookAction; }
    QAction * getReceiveCoinsAction() { return receiveCoinsAction; }
    QAction * getSendCoinsAction() { return sendCoinsAction; }
>>>>>>> Committing original src/qt
=======
    void setWalletModel(WalletModel *walletModel);
>>>>>>> Commiting my updates that turn namecoind into namecoin-qt.

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    bool eventFilter(QObject *object, QEvent *event);

private:
    ClientModel *clientModel;
    WalletModel *walletModel;

    QStackedWidget *centralWidget;

    OverviewPage *overviewPage;
    QWidget *transactionsPage;
    AddressBookPage *addressBookPage;
    AddressBookPage *receiveCoinsPage;
    SendCoinsDialog *sendCoinsPage;
	ManageNamesPage *manageNamesPage;
    SignVerifyMessageDialog *signVerifyMessageDialog;

    QLabel *labelEncryptionIcon;
    QLabel *labelConnectionsIcon;
    QLabel *labelBlocksIcon;
    QLabel *progressBarLabel;
    QProgressBar *progressBar;

    QMenuBar *appMenuBar;
    QAction *overviewAction;
    QAction *historyAction;
    QAction *quitAction;
    QAction *sendCoinsAction;
<<<<<<< HEAD
<<<<<<< HEAD
    QAction *usedSendingAddressesAction;
    QAction *usedReceivingAddressesAction;
=======
=======
	QAction *manageNamesAction;
>>>>>>> Added GUI tab for name_* commands. Version 0.3.60.
    QAction *addressBookAction;
>>>>>>> Committing original src/qt
    QAction *signMessageAction;
    QAction *verifyMessageAction;
    QAction *aboutAction;
    QAction *receiveCoinsAction;
    QAction *optionsAction;
    QAction *toggleHideAction;
    QAction *exportAction;
    QAction *encryptWalletAction;
    QAction *backupWalletAction;
    QAction *changePassphraseAction;
    QAction *aboutQtAction;
    QAction *openRPCConsoleAction;
<<<<<<< HEAD
    QAction *openAction;
    QAction *showHelpMessageAction;

    QSystemTrayIcon *trayIcon;
    Notificator *notificator;
    RPCConsole *rpcConsole;

    /** Keep track of previous number of blocks, to detect progress */
    int prevBlocks;
    int spinnerFrame;

    /** Create the main UI actions. */
    void createActions(bool fIsTestnet);
=======

    QSystemTrayIcon *trayIcon;
    Notificator *notificator;
    TransactionView *transactionView;
    RPCConsole *rpcConsole;

    QMovie *syncIconMovie;
    /** Keep track of previous number of blocks, to detect progress */
    int prevBlocks;

    /** Create the main UI actions. */
    void createActions();
>>>>>>> Committing original src/qt
    /** Create the menu bar and sub-menus. */
    void createMenuBar();
    /** Create the toolbars */
    void createToolBars();
    /** Create system tray icon and notification */
<<<<<<< HEAD
    void createTrayIcon(bool fIsTestnet);
    /** Create system tray menu (or setup the dock menu) */
    void createTrayIconMenu();

    /** Enable or disable all wallet-related actions */
    void setWalletActionsEnabled(bool enabled);

    /** Connect core signals to GUI client */
    void subscribeToCoreSignals();
    /** Disconnect core signals from GUI client */
    void unsubscribeFromCoreSignals();

signals:
    /** Signal raised when a URI was entered or dragged to the GUI */
    void receivedURI(const QString &uri);
=======
    void createTrayIcon();
    /** Create system tray menu (or setup the dock menu) */
    void createTrayIconMenu();
<<<<<<< HEAD
    /** Save window size and position */
    void saveWindowGeometry();
    /** Restore window size and position */
    void restoreWindowGeometry();
>>>>>>> Committing original src/qt
=======
>>>>>>> Commiting my updates that turn namecoind into namecoin-qt.

public slots:
    /** Set number of connections shown in the UI */
    void setNumConnections(int count);
    /** Set number of blocks shown in the UI */
    void setNumBlocks(int count, int nTotalBlocks);
<<<<<<< HEAD
=======
    /** Set the encryption status as shown in the UI.
       @param[in] status            current encryption status
       @see WalletModel::EncryptionStatus
    */
    void setEncryptionStatus(int status);
>>>>>>> Committing original src/qt

    /** Notify the user of an event from the core network or transaction handling code.
       @param[in] title     the message box / notification title
       @param[in] message   the displayed text
       @param[in] style     modality and style definitions (icon and used buttons - buttons only for message boxes)
                            @see CClientUIInterface::MessageBoxFlags
       @param[in] ret       pointer to a bool that will be modified to whether Ok was clicked (modal only)
    */
    void message(const QString &title, const QString &message, unsigned int style, bool *ret = NULL);
<<<<<<< HEAD

#ifdef ENABLE_WALLET
    /** Set the encryption status as shown in the UI.
       @param[in] status            current encryption status
       @see WalletModel::EncryptionStatus
    */
    void setEncryptionStatus(int status);

    bool handlePaymentRequest(const SendCoinsRecipient& recipient);

    /** Show incoming transaction notification for new transactions. */
    void incomingTransaction(const QString& date, int unit, qint64 amount, const QString& type, const QString& address);
#endif

private slots:
#ifdef ENABLE_WALLET
=======
    /** Asks the user whether to pay the transaction fee or to cancel the transaction.
       It is currently not possible to pass a return value to another thread through
       BlockingQueuedConnection, so an indirected pointer is used.
       https://bugreports.qt-project.org/browse/QTBUG-10440

      @param[in] nFeeRequired       the required fee
      @param[out] payFee            true to pay the fee, false to not pay the fee
    */
    void askFee(qint64 nFeeRequired, bool *payFee);
    void handleURI(QString strURI);

private slots:
>>>>>>> Committing original src/qt
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
    /** Switch to manage names page */
    void gotoManageNamesPage();

    /** Show Sign/Verify Message dialog and switch to sign message tab */
    void gotoSignMessageTab(QString addr = "");
    /** Show Sign/Verify Message dialog and switch to verify message tab */
    void gotoVerifyMessageTab(QString addr = "");

<<<<<<< HEAD
    /** Show open dialog */
    void openClicked();
#endif
=======
>>>>>>> Committing original src/qt
    /** Show configuration dialog */
    void optionsClicked();
    /** Show about dialog */
    void aboutClicked();
<<<<<<< HEAD
    /** Show help message dialog */
    void showHelpMessageClicked();
=======
>>>>>>> Committing original src/qt
#ifndef Q_OS_MAC
    /** Handle tray icon clicked */
    void trayIconActivated(QSystemTrayIcon::ActivationReason reason);
#endif
    /** Show incoming transaction notification for new transactions.

        The new items are those between start and end inclusive, under the given parent item.
    */
    void incomingTransaction(const QModelIndex& parent, int start, int /*end*/);
    /** Encrypt the wallet */
    void encryptWallet(bool status);
    /** Backup the wallet */
    void backupWallet();
    /** Change encrypted wallet passphrase */
    void changePassphrase();
    /** Ask for passphrase to unlock wallet temporarily */
    void unlockWallet();

    /** Show window if hidden, unminimize when minimized, rise when obscured or show if hidden and fToggleHidden is true */
    void showNormalIfMinimized(bool fToggleHidden = false);
    /** Simply calls showNormalIfMinimized(true) for use in SLOT() macro */
    void toggleHidden();
};

#endif // BITCOINGUI_H
