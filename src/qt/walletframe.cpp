<<<<<<< HEAD
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "walletframe.h"

#include "bitcoingui.h"
#include "walletview.h"

#include <cstdio>

#include <QHBoxLayout>
#include <QLabel>

WalletFrame::WalletFrame(BitcoinGUI *_gui) :
    QFrame(_gui),
    gui(_gui)
=======
/*
 * Qt4 bitcoin GUI.
 *
 * W.J. van der Laan 2011-2012
 * The Bitcoin Developers 2011-2013
 */
#include "walletframe.h"
#include "bitcoingui.h"
#include "walletstack.h"

#include <QVBoxLayout>
#include <QMessageBox>

#include <stdio.h>

WalletFrame::WalletFrame(BitcoinGUI *_gui) :
    QFrame(_gui),
    gui(_gui),
    clientModel(0)
>>>>>>> Committing original src/qt
{
    // Leave HBox hook for adding a list view later
    QHBoxLayout *walletFrameLayout = new QHBoxLayout(this);
    setContentsMargins(0,0,0,0);
<<<<<<< HEAD
    walletStack = new QStackedWidget(this);
    walletFrameLayout->setContentsMargins(0,0,0,0);
    walletFrameLayout->addWidget(walletStack);

    QLabel *noWallet = new QLabel(tr("No wallet has been loaded."));
    noWallet->setAlignment(Qt::AlignCenter);
    walletStack->addWidget(noWallet);
=======
    walletStack = new WalletStack(this);
    walletStack->setBitcoinGUI(gui);
    walletFrameLayout->setContentsMargins(0,0,0,0);
    walletFrameLayout->addWidget(walletStack);
>>>>>>> Committing original src/qt
}

WalletFrame::~WalletFrame()
{
}

void WalletFrame::setClientModel(ClientModel *clientModel)
{
    this->clientModel = clientModel;
<<<<<<< HEAD
=======
    walletStack->setClientModel(clientModel);
>>>>>>> Committing original src/qt
}

bool WalletFrame::addWallet(const QString& name, WalletModel *walletModel)
{
<<<<<<< HEAD
    if (!gui || !clientModel || !walletModel || mapWalletViews.count(name) > 0)
        return false;

    WalletView *walletView = new WalletView(this);
    walletView->setBitcoinGUI(gui);
    walletView->setClientModel(clientModel);
    walletView->setWalletModel(walletModel);
    walletView->showOutOfSyncWarning(bOutOfSync);

     /* TODO we should goto the currently selected page once dynamically adding wallets is supported */
    walletView->gotoOverviewPage();
    walletStack->addWidget(walletView);
    mapWalletViews[name] = walletView;

    // Ensure a walletView is able to show the main window
    connect(walletView, SIGNAL(showNormalIfMinimized()), gui, SLOT(showNormalIfMinimized()));

    return true;
=======
    return walletStack->addWallet(name, walletModel);
>>>>>>> Committing original src/qt
}

bool WalletFrame::setCurrentWallet(const QString& name)
{
<<<<<<< HEAD
    if (mapWalletViews.count(name) == 0)
        return false;

    WalletView *walletView = mapWalletViews.value(name);
    walletStack->setCurrentWidget(walletView);
    walletView->updateEncryptionStatus();
    return true;
}

bool WalletFrame::removeWallet(const QString &name)
{
    if (mapWalletViews.count(name) == 0)
        return false;

    WalletView *walletView = mapWalletViews.take(name);
    walletStack->removeWidget(walletView);
=======
    // TODO: Check if valid name
    walletStack->setCurrentWallet(name);
>>>>>>> Committing original src/qt
    return true;
}

void WalletFrame::removeAllWallets()
{
<<<<<<< HEAD
    QMap<QString, WalletView*>::const_iterator i;
    for (i = mapWalletViews.constBegin(); i != mapWalletViews.constEnd(); ++i)
        walletStack->removeWidget(i.value());
    mapWalletViews.clear();
}

bool WalletFrame::handlePaymentRequest(const SendCoinsRecipient &recipient)
{
    WalletView *walletView = currentWalletView();
    if (!walletView)
        return false;

    return walletView->handlePaymentRequest(recipient);
=======
    walletStack->removeAllWallets();
}

bool WalletFrame::handleURI(const QString &uri)
{
    return walletStack->handleURI(uri);
>>>>>>> Committing original src/qt
}

void WalletFrame::showOutOfSyncWarning(bool fShow)
{
<<<<<<< HEAD
    bOutOfSync = fShow;
    QMap<QString, WalletView*>::const_iterator i;
    for (i = mapWalletViews.constBegin(); i != mapWalletViews.constEnd(); ++i)
        i.value()->showOutOfSyncWarning(fShow);
=======
    if (!walletStack) {
        QMessageBox box;
        box.setText("walletStack is null");
        box.exec();
        return;
    }
    walletStack->showOutOfSyncWarning(fShow);
>>>>>>> Committing original src/qt
}

void WalletFrame::gotoOverviewPage()
{
<<<<<<< HEAD
    QMap<QString, WalletView*>::const_iterator i;
    for (i = mapWalletViews.constBegin(); i != mapWalletViews.constEnd(); ++i)
        i.value()->gotoOverviewPage();
=======
    walletStack->gotoOverviewPage();
>>>>>>> Committing original src/qt
}

void WalletFrame::gotoHistoryPage()
{
<<<<<<< HEAD
    QMap<QString, WalletView*>::const_iterator i;
    for (i = mapWalletViews.constBegin(); i != mapWalletViews.constEnd(); ++i)
        i.value()->gotoHistoryPage();
=======
    walletStack->gotoHistoryPage();
}

void WalletFrame::gotoAddressBookPage()
{
    walletStack->gotoAddressBookPage();
>>>>>>> Committing original src/qt
}

void WalletFrame::gotoReceiveCoinsPage()
{
<<<<<<< HEAD
    QMap<QString, WalletView*>::const_iterator i;
    for (i = mapWalletViews.constBegin(); i != mapWalletViews.constEnd(); ++i)
        i.value()->gotoReceiveCoinsPage();
=======
    walletStack->gotoReceiveCoinsPage();
>>>>>>> Committing original src/qt
}

void WalletFrame::gotoSendCoinsPage(QString addr)
{
<<<<<<< HEAD
    QMap<QString, WalletView*>::const_iterator i;
    for (i = mapWalletViews.constBegin(); i != mapWalletViews.constEnd(); ++i)
        i.value()->gotoSendCoinsPage(addr);
=======
    walletStack->gotoSendCoinsPage(addr);
>>>>>>> Committing original src/qt
}

void WalletFrame::gotoSignMessageTab(QString addr)
{
<<<<<<< HEAD
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->gotoSignMessageTab(addr);
=======
    walletStack->gotoSignMessageTab(addr);
>>>>>>> Committing original src/qt
}

void WalletFrame::gotoVerifyMessageTab(QString addr)
{
<<<<<<< HEAD
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->gotoVerifyMessageTab(addr);
=======
    walletStack->gotoSignMessageTab(addr);
>>>>>>> Committing original src/qt
}

void WalletFrame::encryptWallet(bool status)
{
<<<<<<< HEAD
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->encryptWallet(status);
=======
    walletStack->encryptWallet(status);
>>>>>>> Committing original src/qt
}

void WalletFrame::backupWallet()
{
<<<<<<< HEAD
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->backupWallet();
=======
    walletStack->backupWallet();
>>>>>>> Committing original src/qt
}

void WalletFrame::changePassphrase()
{
<<<<<<< HEAD
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->changePassphrase();
=======
    walletStack->changePassphrase();
>>>>>>> Committing original src/qt
}

void WalletFrame::unlockWallet()
{
<<<<<<< HEAD
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->unlockWallet();
}

void WalletFrame::usedSendingAddresses()
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->usedSendingAddresses();
}

void WalletFrame::usedReceivingAddresses()
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->usedReceivingAddresses();
}

WalletView *WalletFrame::currentWalletView()
{
    return qobject_cast<WalletView*>(walletStack->currentWidget());
}

=======
    walletStack->unlockWallet();
}

void WalletFrame::setEncryptionStatus()
{
    walletStack->setEncryptionStatus();
}
>>>>>>> Committing original src/qt
