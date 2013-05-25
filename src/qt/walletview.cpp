<<<<<<< HEAD
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "walletview.h"

#include "addressbookpage.h"
#include "askpassphrasedialog.h"
#include "bitcoingui.h"
#include "clientmodel.h"
#include "guiutil.h"
#include "optionsmodel.h"
#include "overviewpage.h"
#include "receivecoinsdialog.h"
#include "sendcoinsdialog.h"
#include "signverifymessagedialog.h"
#include "transactiontablemodel.h"
#include "transactionview.h"
#include "walletmodel.h"

#include "ui_interface.h"

#include <QAction>
#include <QActionGroup>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

WalletView::WalletView(QWidget *parent):
    QStackedWidget(parent),
=======
/*
 * Qt4 bitcoin GUI.
 *
 * W.J. van der Laan 2011-2012
 * The Bitcoin Developers 2011-2013
 */
#include "walletview.h"
#include "bitcoingui.h"
#include "transactiontablemodel.h"
#include "addressbookpage.h"
#include "sendcoinsdialog.h"
#include "signverifymessagedialog.h"
#include "clientmodel.h"
#include "walletmodel.h"
#include "optionsmodel.h"
#include "transactionview.h"
#include "overviewpage.h"
#include "askpassphrasedialog.h"
#include "ui_interface.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QAction>
#include <QDesktopServices>
#include <QFileDialog>
#include <QPushButton>

WalletView::WalletView(QWidget *parent, BitcoinGUI *_gui):
    QStackedWidget(parent),
    gui(_gui),
>>>>>>> Committing original src/qt
    clientModel(0),
    walletModel(0)
{
    // Create tabs
    overviewPage = new OverviewPage();

    transactionsPage = new QWidget(this);
    QVBoxLayout *vbox = new QVBoxLayout();
    QHBoxLayout *hbox_buttons = new QHBoxLayout();
    transactionView = new TransactionView(this);
    vbox->addWidget(transactionView);
    QPushButton *exportButton = new QPushButton(tr("&Export"), this);
    exportButton->setToolTip(tr("Export the data in the current tab to a file"));
#ifndef Q_OS_MAC // Icons on push buttons are very uncommon on Mac
    exportButton->setIcon(QIcon(":/icons/export"));
#endif
    hbox_buttons->addStretch();
    hbox_buttons->addWidget(exportButton);
    vbox->addLayout(hbox_buttons);
    transactionsPage->setLayout(vbox);

<<<<<<< HEAD
    receiveCoinsPage = new ReceiveCoinsDialog();
    sendCoinsPage = new SendCoinsDialog();

    addWidget(overviewPage);
    addWidget(transactionsPage);
    addWidget(receiveCoinsPage);
    addWidget(sendCoinsPage);

    // Clicking on a transaction on the overview pre-selects the transaction on the transaction history page
=======
    addressBookPage = new AddressBookPage(AddressBookPage::ForEditing, AddressBookPage::SendingTab);

    receiveCoinsPage = new AddressBookPage(AddressBookPage::ForEditing, AddressBookPage::ReceivingTab);

    sendCoinsPage = new SendCoinsDialog(gui);

    signVerifyMessageDialog = new SignVerifyMessageDialog(gui);

    addWidget(overviewPage);
    addWidget(transactionsPage);
    addWidget(addressBookPage);
    addWidget(receiveCoinsPage);
    addWidget(sendCoinsPage);

    // Clicking on a transaction on the overview page simply sends you to transaction history page
    connect(overviewPage, SIGNAL(transactionClicked(QModelIndex)), this, SLOT(gotoHistoryPage()));
>>>>>>> Committing original src/qt
    connect(overviewPage, SIGNAL(transactionClicked(QModelIndex)), transactionView, SLOT(focusTransaction(QModelIndex)));

    // Double-clicking on a transaction on the transaction history page shows details
    connect(transactionView, SIGNAL(doubleClicked(QModelIndex)), transactionView, SLOT(showDetails()));

<<<<<<< HEAD
    // Clicking on "Export" allows to export the transaction list
    connect(exportButton, SIGNAL(clicked()), transactionView, SLOT(exportClicked()));

    // Pass through messages from sendCoinsPage
    connect(sendCoinsPage, SIGNAL(message(QString,QString,unsigned int)), this, SIGNAL(message(QString,QString,unsigned int)));
    // Pass through messages from transactionView
    connect(transactionView, SIGNAL(message(QString,QString,unsigned int)), this, SIGNAL(message(QString,QString,unsigned int)));
=======
    // Clicking on "Send Coins" in the address book sends you to the send coins tab
    connect(addressBookPage, SIGNAL(sendCoins(QString)), this, SLOT(gotoSendCoinsPage(QString)));
    // Clicking on "Verify Message" in the address book opens the verify message tab in the Sign/Verify Message dialog
    connect(addressBookPage, SIGNAL(verifyMessage(QString)), this, SLOT(gotoVerifyMessageTab(QString)));
    // Clicking on "Sign Message" in the receive coins page opens the sign message tab in the Sign/Verify Message dialog
    connect(receiveCoinsPage, SIGNAL(signMessage(QString)), this, SLOT(gotoSignMessageTab(QString)));
    // Clicking on "Export" allows to export the transaction list
    connect(exportButton, SIGNAL(clicked()), transactionView, SLOT(exportClicked()));

    gotoOverviewPage();
>>>>>>> Committing original src/qt
}

WalletView::~WalletView()
{
}

void WalletView::setBitcoinGUI(BitcoinGUI *gui)
{
<<<<<<< HEAD
    if (gui)
    {
        // Clicking on a transaction on the overview page simply sends you to transaction history page
        connect(overviewPage, SIGNAL(transactionClicked(QModelIndex)), gui, SLOT(gotoHistoryPage()));

        // Receive and report messages
        connect(this, SIGNAL(message(QString,QString,unsigned int)), gui, SLOT(message(QString,QString,unsigned int)));

        // Pass through encryption status changed signals
        connect(this, SIGNAL(encryptionStatusChanged(int)), gui, SLOT(setEncryptionStatus(int)));

        // Pass through transaction notifications
        connect(this, SIGNAL(incomingTransaction(QString,int,qint64,QString,QString)), gui, SLOT(incomingTransaction(QString,int,qint64,QString,QString)));
    }
=======
    this->gui = gui;
>>>>>>> Committing original src/qt
}

void WalletView::setClientModel(ClientModel *clientModel)
{
    this->clientModel = clientModel;
<<<<<<< HEAD

    overviewPage->setClientModel(clientModel);
=======
    if (clientModel)
    {
        overviewPage->setClientModel(clientModel);
        addressBookPage->setOptionsModel(clientModel->getOptionsModel());
        receiveCoinsPage->setOptionsModel(clientModel->getOptionsModel());
    }
>>>>>>> Committing original src/qt
}

void WalletView::setWalletModel(WalletModel *walletModel)
{
    this->walletModel = walletModel;
<<<<<<< HEAD

    // Put transaction list in tabs
    transactionView->setModel(walletModel);
    overviewPage->setWalletModel(walletModel);
    receiveCoinsPage->setModel(walletModel);
    sendCoinsPage->setModel(walletModel);

    if (walletModel)
    {
        // Receive and pass through messages from wallet model
        connect(walletModel, SIGNAL(message(QString,QString,unsigned int)), this, SIGNAL(message(QString,QString,unsigned int)));

        // Handle changes in encryption status
        connect(walletModel, SIGNAL(encryptionStatusChanged(int)), this, SIGNAL(encryptionStatusChanged(int)));
        updateEncryptionStatus();

        // Balloon pop-up for new transaction
        connect(walletModel->getTransactionTableModel(), SIGNAL(rowsInserted(QModelIndex,int,int)),
                this, SLOT(processNewTransaction(QModelIndex,int,int)));
=======
    if (walletModel)
    {
        // Receive and report messages from wallet thread
        connect(walletModel, SIGNAL(message(QString,QString,unsigned int)), gui, SLOT(message(QString,QString,unsigned int)));

        // Put transaction list in tabs
        transactionView->setModel(walletModel);
        overviewPage->setWalletModel(walletModel);
        addressBookPage->setModel(walletModel->getAddressTableModel());
        receiveCoinsPage->setModel(walletModel->getAddressTableModel());
        sendCoinsPage->setModel(walletModel);
        signVerifyMessageDialog->setModel(walletModel);

        setEncryptionStatus();
        connect(walletModel, SIGNAL(encryptionStatusChanged(int)), gui, SLOT(setEncryptionStatus(int)));

        // Balloon pop-up for new transaction
        connect(walletModel->getTransactionTableModel(), SIGNAL(rowsInserted(QModelIndex,int,int)),
                this, SLOT(incomingTransaction(QModelIndex,int,int)));
>>>>>>> Committing original src/qt

        // Ask for passphrase if needed
        connect(walletModel, SIGNAL(requireUnlock()), this, SLOT(unlockWallet()));
    }
}

<<<<<<< HEAD
void WalletView::processNewTransaction(const QModelIndex& parent, int start, int /*end*/)
{
    // Prevent balloon-spam when initial block download is in progress
    if (!walletModel || !clientModel || clientModel->inInitialBlockDownload())
=======
void WalletView::incomingTransaction(const QModelIndex& parent, int start, int /*end*/)
{
    // Prevent balloon-spam when initial block download is in progress
    if(!walletModel || !clientModel || clientModel->inInitialBlockDownload())
>>>>>>> Committing original src/qt
        return;

    TransactionTableModel *ttm = walletModel->getTransactionTableModel();

    QString date = ttm->index(start, TransactionTableModel::Date, parent).data().toString();
    qint64 amount = ttm->index(start, TransactionTableModel::Amount, parent).data(Qt::EditRole).toULongLong();
    QString type = ttm->index(start, TransactionTableModel::Type, parent).data().toString();
    QString address = ttm->index(start, TransactionTableModel::ToAddress, parent).data().toString();

<<<<<<< HEAD
    emit incomingTransaction(date, walletModel->getOptionsModel()->getDisplayUnit(), amount, type, address);
=======
    gui->incomingTransaction(date, walletModel->getOptionsModel()->getDisplayUnit(), amount, type, address);
>>>>>>> Committing original src/qt
}

void WalletView::gotoOverviewPage()
{
<<<<<<< HEAD
=======
    gui->getOverviewAction()->setChecked(true);
>>>>>>> Committing original src/qt
    setCurrentWidget(overviewPage);
}

void WalletView::gotoHistoryPage()
{
<<<<<<< HEAD
    setCurrentWidget(transactionsPage);
}

void WalletView::gotoReceiveCoinsPage()
{
=======
    gui->getHistoryAction()->setChecked(true);
    setCurrentWidget(transactionsPage);
}

void WalletView::gotoAddressBookPage()
{
    gui->getAddressBookAction()->setChecked(true);
    setCurrentWidget(addressBookPage);
}

void WalletView::gotoReceiveCoinsPage()
{
    gui->getReceiveCoinsAction()->setChecked(true);
>>>>>>> Committing original src/qt
    setCurrentWidget(receiveCoinsPage);
}

void WalletView::gotoSendCoinsPage(QString addr)
{
<<<<<<< HEAD
=======
    gui->getSendCoinsAction()->setChecked(true);
>>>>>>> Committing original src/qt
    setCurrentWidget(sendCoinsPage);

    if (!addr.isEmpty())
        sendCoinsPage->setAddress(addr);
}

void WalletView::gotoSignMessageTab(QString addr)
{
<<<<<<< HEAD
    // calls show() in showTab_SM()
    SignVerifyMessageDialog *signVerifyMessageDialog = new SignVerifyMessageDialog(this);
    signVerifyMessageDialog->setAttribute(Qt::WA_DeleteOnClose);
    signVerifyMessageDialog->setModel(walletModel);
=======
    // call show() in showTab_SM()
>>>>>>> Committing original src/qt
    signVerifyMessageDialog->showTab_SM(true);

    if (!addr.isEmpty())
        signVerifyMessageDialog->setAddress_SM(addr);
}

void WalletView::gotoVerifyMessageTab(QString addr)
{
<<<<<<< HEAD
    // calls show() in showTab_VM()
    SignVerifyMessageDialog *signVerifyMessageDialog = new SignVerifyMessageDialog(this);
    signVerifyMessageDialog->setAttribute(Qt::WA_DeleteOnClose);
    signVerifyMessageDialog->setModel(walletModel);
=======
    // call show() in showTab_VM()
>>>>>>> Committing original src/qt
    signVerifyMessageDialog->showTab_VM(true);

    if (!addr.isEmpty())
        signVerifyMessageDialog->setAddress_VM(addr);
}

<<<<<<< HEAD
bool WalletView::handlePaymentRequest(const SendCoinsRecipient& recipient)
{
    return sendCoinsPage->handlePaymentRequest(recipient);
=======
bool WalletView::handleURI(const QString& strURI)
{
    // URI has to be valid
    if (sendCoinsPage->handleURI(strURI))
    {
        gotoSendCoinsPage();
        return true;
    }
    else
        return false;
>>>>>>> Committing original src/qt
}

void WalletView::showOutOfSyncWarning(bool fShow)
{
    overviewPage->showOutOfSyncWarning(fShow);
}

<<<<<<< HEAD
void WalletView::updateEncryptionStatus()
{
    emit encryptionStatusChanged(walletModel->getEncryptionStatus());
=======
void WalletView::setEncryptionStatus()
{
    gui->setEncryptionStatus(walletModel->getEncryptionStatus());
>>>>>>> Committing original src/qt
}

void WalletView::encryptWallet(bool status)
{
    if(!walletModel)
        return;
    AskPassphraseDialog dlg(status ? AskPassphraseDialog::Encrypt : AskPassphraseDialog::Decrypt, this);
    dlg.setModel(walletModel);
    dlg.exec();

<<<<<<< HEAD
    updateEncryptionStatus();
=======
    setEncryptionStatus();
>>>>>>> Committing original src/qt
}

void WalletView::backupWallet()
{
<<<<<<< HEAD
    QString filename = GUIUtil::getSaveFileName(this,
        tr("Backup Wallet"), QString(),
        tr("Wallet Data (*.dat)"), NULL);

    if (filename.isEmpty())
        return;

    if (!walletModel->backupWallet(filename)) {
        emit message(tr("Backup Failed"), tr("There was an error trying to save the wallet data to %1.").arg(filename),
            CClientUIInterface::MSG_ERROR);
        }
    else {
        emit message(tr("Backup Successful"), tr("The wallet data was successfully saved to %1.").arg(filename),
            CClientUIInterface::MSG_INFORMATION);
=======
    QString saveDir = QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation);
    QString filename = QFileDialog::getSaveFileName(this, tr("Backup Wallet"), saveDir, tr("Wallet Data (*.dat)"));
    if (!filename.isEmpty()) {
        if (!walletModel->backupWallet(filename)) {
            gui->message(tr("Backup Failed"), tr("There was an error trying to save the wallet data to the new location."),
                      CClientUIInterface::MSG_ERROR);
        }
        else
            gui->message(tr("Backup Successful"), tr("The wallet data was successfully saved to the new location."),
                      CClientUIInterface::MSG_INFORMATION);
>>>>>>> Committing original src/qt
    }
}

void WalletView::changePassphrase()
{
    AskPassphraseDialog dlg(AskPassphraseDialog::ChangePass, this);
    dlg.setModel(walletModel);
    dlg.exec();
}

void WalletView::unlockWallet()
{
    if(!walletModel)
        return;
    // Unlock wallet when requested by wallet model
    if (walletModel->getEncryptionStatus() == WalletModel::Locked)
    {
        AskPassphraseDialog dlg(AskPassphraseDialog::Unlock, this);
        dlg.setModel(walletModel);
        dlg.exec();
    }
}
<<<<<<< HEAD

void WalletView::usedSendingAddresses()
{
    if(!walletModel)
        return;
    AddressBookPage *dlg = new AddressBookPage(AddressBookPage::ForEditing, AddressBookPage::SendingTab, this);
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    dlg->setModel(walletModel->getAddressTableModel());
    dlg->show();
}

void WalletView::usedReceivingAddresses()
{
    if(!walletModel)
        return;
    AddressBookPage *dlg = new AddressBookPage(AddressBookPage::ForEditing, AddressBookPage::ReceivingTab, this);
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    dlg->setModel(walletModel->getAddressTableModel());
    dlg->show();
}
=======
>>>>>>> Committing original src/qt
