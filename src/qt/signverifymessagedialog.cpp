<<<<<<< HEAD
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

=======
>>>>>>> Committing original src/qt
#include "signverifymessagedialog.h"
#include "ui_signverifymessagedialog.h"

#include "addressbookpage.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "guiutil.h"
#include "walletmodel.h"

#include "base58.h"
#include "init.h"
#include "wallet.h"

#include <string>
#include <vector>

#include <QClipboard>

=======
#include "base58.h"
=======
#include "../headers.h"
>>>>>>> Commiting my updates that turn namecoind into namecoin-qt.
#include "guiutil.h"
#include "../init.h"
#include "../wallet.h"
#include "optionsmodel.h"
#include "walletmodel.h"

#include <QClipboard>

#include <string>
#include <vector>

<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> Committing original src/qt
=======
const static std::string strMessageMagic = "Bitcoin Signed Message:\n";

>>>>>>> Commiting my updates that turn namecoind into namecoin-qt.
=======
>>>>>>> Added RPC commands: signmessage, verifymessage, listunspent, listaddressgroupings.
SignVerifyMessageDialog::SignVerifyMessageDialog(QWidget *parent) :
    QDialog(parent, Qt::WindowSystemMenuHint | Qt::WindowTitleHint),
    ui(new Ui::SignVerifyMessageDialog),
    model(0)
{
    ui->setupUi(this);

<<<<<<< HEAD
#if QT_VERSION >= 0x040700
    ui->signatureOut_SM->setPlaceholderText(tr("Click \"Sign Message\" to generate signature"));
    ui->addressIn_VM->setPlaceholderText(tr("Enter a Bitcoin address (e.g. 1NS17iag9jJgTHD1VXjvLCEnZuQ3rJDE9L)"));
=======
#if (QT_VERSION >= 0x040700)
    /* Do not move this to the XML file, Qt before 4.7 will choke on it */
    ui->addressIn_SM->setPlaceholderText(tr("Enter a Namecoin address (e.g. N1KHAL5C1CRzy58NdJwp1tbLze3XrkFxx9)"));
    ui->signatureOut_SM->setPlaceholderText(tr("Click \"Sign Message\" to generate signature"));

<<<<<<< HEAD
    ui->addressIn_VM->setPlaceholderText(tr("Enter a Bitcoin address (e.g. 1NS17iag9jJgTHD1VXjvLCEnZuQ3rJDE9L)"));
    ui->signatureIn_VM->setPlaceholderText(tr("Enter Bitcoin signature"));
>>>>>>> Committing original src/qt
=======
    ui->addressIn_VM->setPlaceholderText(tr("Enter a Namecoin address (e.g. N1KHAL5C1CRzy58NdJwp1tbLze3XrkFxx9)"));
    ui->signatureIn_VM->setPlaceholderText(tr("Enter Namecoin signature"));
>>>>>>> Commiting my updates that turn namecoind into namecoin-qt.
#endif

    GUIUtil::setupAddressWidget(ui->addressIn_SM, this);
    GUIUtil::setupAddressWidget(ui->addressIn_VM, this);

    ui->addressIn_SM->installEventFilter(this);
    ui->messageIn_SM->installEventFilter(this);
    ui->signatureOut_SM->installEventFilter(this);
    ui->addressIn_VM->installEventFilter(this);
    ui->messageIn_VM->installEventFilter(this);
    ui->signatureIn_VM->installEventFilter(this);

    ui->signatureOut_SM->setFont(GUIUtil::bitcoinAddressFont());
    ui->signatureIn_VM->setFont(GUIUtil::bitcoinAddressFont());
}

SignVerifyMessageDialog::~SignVerifyMessageDialog()
{
    delete ui;
}

void SignVerifyMessageDialog::setModel(WalletModel *model)
{
    this->model = model;
}

void SignVerifyMessageDialog::setAddress_SM(const QString &address)
{
    ui->addressIn_SM->setText(address);
    ui->messageIn_SM->setFocus();
}

void SignVerifyMessageDialog::setAddress_VM(const QString &address)
{
    ui->addressIn_VM->setText(address);
    ui->messageIn_VM->setFocus();
}

void SignVerifyMessageDialog::showTab_SM(bool fShow)
{
    ui->tabWidget->setCurrentIndex(0);
<<<<<<< HEAD
=======

>>>>>>> Committing original src/qt
    if (fShow)
        this->show();
}

void SignVerifyMessageDialog::showTab_VM(bool fShow)
{
    ui->tabWidget->setCurrentIndex(1);
    if (fShow)
        this->show();
}

void SignVerifyMessageDialog::on_addressBookButton_SM_clicked()
{
    if (model && model->getAddressTableModel())
    {
<<<<<<< HEAD
        AddressBookPage dlg(AddressBookPage::ForSelection, AddressBookPage::ReceivingTab, this);
=======
        AddressBookPage dlg(AddressBookPage::ForSending, AddressBookPage::ReceivingTab, this);
>>>>>>> Committing original src/qt
        dlg.setModel(model->getAddressTableModel());
        if (dlg.exec())
        {
            setAddress_SM(dlg.getReturnValue());
        }
    }
}

void SignVerifyMessageDialog::on_pasteButton_SM_clicked()
{
    setAddress_SM(QApplication::clipboard()->text());
}

void SignVerifyMessageDialog::on_signMessageButton_SM_clicked()
{
<<<<<<< HEAD
    if (!model)
        return;

=======
>>>>>>> Committing original src/qt
    /* Clear old signature to ensure users don't get confused on error with an old signature displayed */
    ui->signatureOut_SM->clear();

    uint160 hash160;
    if (!AddressToHash160(qPrintable(ui->addressIn_SM->text()), hash160))
    {
<<<<<<< HEAD
=======
        ui->addressIn_SM->setValid(false);
>>>>>>> Committing original src/qt
        ui->statusLabel_SM->setStyleSheet("QLabel { color: red; }");
        ui->statusLabel_SM->setText(tr("The entered address is invalid.") + QString(" ") + tr("Please check the address and try again."));
        return;
    }

    WalletModel::UnlockContext ctx(model->requestUnlock());
    if (!ctx.isValid())
    {
        ui->statusLabel_SM->setStyleSheet("QLabel { color: red; }");
        ui->statusLabel_SM->setText(tr("Wallet unlock was cancelled."));
        return;
    }

    CPrivKey privKey;
    bool found = false;
    CRITICAL_BLOCK(pwalletMain->cs_mapKeys)
    {
        std::map<uint160, std::vector<unsigned char> >::const_iterator mi = pwalletMain->mapPubKeys.find(hash160);
        if (mi != pwalletMain->mapPubKeys.end() && pwalletMain->GetPrivKey(mi->second, privKey))
            found = true;
    }
    if (!found)
    {
        ui->statusLabel_SM->setStyleSheet("QLabel { color: red; }");
        ui->statusLabel_SM->setText(tr("Private key for the entered address is not available."));
        return;
    }

    CDataStream ss(SER_GETHASH, 0);
    ss << strMessageMagic;
    ss << ui->messageIn_SM->document()->toPlainText().toStdString();

    std::vector<unsigned char> vchSig;
    CKey key;
    key.SetPrivKey(privKey);
    if (!key.SignCompact(Hash(ss.begin(), ss.end()), vchSig))
    {
        ui->statusLabel_SM->setStyleSheet("QLabel { color: red; }");
        ui->statusLabel_SM->setText(QString("<nobr>") + tr("Message signing failed.") + QString("</nobr>"));
        return;
    }

    ui->statusLabel_SM->setStyleSheet("QLabel { color: green; }");
    ui->statusLabel_SM->setText(QString("<nobr>") + tr("Message signed.") + QString("</nobr>"));

    ui->signatureOut_SM->setText(QString::fromStdString(EncodeBase64(&vchSig[0], vchSig.size())));
}

void SignVerifyMessageDialog::on_copySignatureButton_SM_clicked()
{
<<<<<<< HEAD
    GUIUtil::setClipboard(ui->signatureOut_SM->text());
=======
    QApplication::clipboard()->setText(ui->signatureOut_SM->text());
>>>>>>> Committing original src/qt
}

void SignVerifyMessageDialog::on_clearButton_SM_clicked()
{
    ui->addressIn_SM->clear();
    ui->messageIn_SM->clear();
    ui->signatureOut_SM->clear();
    ui->statusLabel_SM->clear();

    ui->addressIn_SM->setFocus();
}

void SignVerifyMessageDialog::on_addressBookButton_VM_clicked()
{
    if (model && model->getAddressTableModel())
    {
<<<<<<< HEAD
        AddressBookPage dlg(AddressBookPage::ForSelection, AddressBookPage::SendingTab, this);
=======
        AddressBookPage dlg(AddressBookPage::ForSending, AddressBookPage::SendingTab, this);
>>>>>>> Committing original src/qt
        dlg.setModel(model->getAddressTableModel());
        if (dlg.exec())
        {
            setAddress_VM(dlg.getReturnValue());
        }
    }
}

void SignVerifyMessageDialog::on_verifyMessageButton_VM_clicked()
{
    uint160 hash160;
    if (!AddressToHash160(qPrintable(ui->addressIn_VM->text()), hash160))
    {
<<<<<<< HEAD
=======
        ui->addressIn_VM->setValid(false);
>>>>>>> Committing original src/qt
        ui->statusLabel_VM->setStyleSheet("QLabel { color: red; }");
        ui->statusLabel_VM->setText(tr("The entered address is invalid.") + QString(" ") + tr("Please check the address and try again."));
        return;
    }

    bool fInvalid = false;
    std::vector<unsigned char> vchSig = DecodeBase64(ui->signatureIn_VM->text().toStdString().c_str(), &fInvalid);

    if (fInvalid)
    {
        ui->signatureIn_VM->setValid(false);
        ui->statusLabel_VM->setStyleSheet("QLabel { color: red; }");
        ui->statusLabel_VM->setText(tr("The signature could not be decoded.") + QString(" ") + tr("Please check the signature and try again."));
        return;
    }

    CDataStream ss(SER_GETHASH, 0);
    ss << strMessageMagic;
    ss << ui->messageIn_VM->document()->toPlainText().toStdString();

<<<<<<< HEAD
    CPubKey pubkey;
    if (!pubkey.RecoverCompact(Hash(ss.begin(), ss.end()), vchSig))
=======
    CKey key;
    if (!key.SetCompactSignature(Hash(ss.begin(), ss.end()), vchSig))
>>>>>>> Committing original src/qt
    {
        ui->signatureIn_VM->setValid(false);
        ui->statusLabel_VM->setStyleSheet("QLabel { color: red; }");
        ui->statusLabel_VM->setText(tr("The signature did not match the message digest.") + QString(" ") + tr("Please check the signature and try again."));
        return;
    }

<<<<<<< HEAD
<<<<<<< HEAD
    if (!(CBitcoinAddress(pubkey.GetID()) == addr))
=======
    if (!(CBitcoinAddress(key.GetPubKey().GetID()) == addr))
>>>>>>> Committing original src/qt
=======
    if (Hash160(key.GetPubKey()) != hash160)
>>>>>>> Commiting my updates that turn namecoind into namecoin-qt.
    {
        ui->statusLabel_VM->setStyleSheet("QLabel { color: red; }");
        ui->statusLabel_VM->setText(QString("<nobr>") + tr("Message verification failed.") + QString("</nobr>"));
        return;
    }

    ui->statusLabel_VM->setStyleSheet("QLabel { color: green; }");
    ui->statusLabel_VM->setText(QString("<nobr>") + tr("Message verified.") + QString("</nobr>"));
}

void SignVerifyMessageDialog::on_clearButton_VM_clicked()
{
    ui->addressIn_VM->clear();
    ui->signatureIn_VM->clear();
    ui->messageIn_VM->clear();
    ui->statusLabel_VM->clear();

    ui->addressIn_VM->setFocus();
}

bool SignVerifyMessageDialog::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::FocusIn)
    {
        if (ui->tabWidget->currentIndex() == 0)
        {
            /* Clear status message on focus change */
            ui->statusLabel_SM->clear();

            /* Select generated signature */
            if (object == ui->signatureOut_SM)
            {
                ui->signatureOut_SM->selectAll();
                return true;
            }
        }
        else if (ui->tabWidget->currentIndex() == 1)
        {
            /* Clear status message on focus change */
            ui->statusLabel_VM->clear();
        }
    }
    return QDialog::eventFilter(object, event);
}
