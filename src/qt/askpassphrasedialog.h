<<<<<<< HEAD
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

=======
>>>>>>> Committing original src/qt
#ifndef ASKPASSPHRASEDIALOG_H
#define ASKPASSPHRASEDIALOG_H

#include <QDialog>

<<<<<<< HEAD
class WalletModel;

namespace Ui {
    class AskPassphraseDialog;
}
=======
namespace Ui {
    class AskPassphraseDialog;
}
class WalletModel;
>>>>>>> Committing original src/qt

/** Multifunctional dialog to ask for passphrases. Used for encryption, unlocking, and changing the passphrase.
 */
class AskPassphraseDialog : public QDialog
{
    Q_OBJECT

public:
    enum Mode {
        Encrypt,    /**< Ask passphrase twice and encrypt */
        Unlock,     /**< Ask passphrase and unlock */
        ChangePass, /**< Ask old passphrase + new passphrase twice */
        Decrypt     /**< Ask passphrase and decrypt wallet */
    };

<<<<<<< HEAD
    explicit AskPassphraseDialog(Mode mode, QWidget *parent);
=======
    explicit AskPassphraseDialog(Mode mode, QWidget *parent = 0);
>>>>>>> Committing original src/qt
    ~AskPassphraseDialog();

    void accept();

    void setModel(WalletModel *model);

private:
    Ui::AskPassphraseDialog *ui;
    Mode mode;
    WalletModel *model;
    bool fCapsLock;

private slots:
    void textChanged();
<<<<<<< HEAD

protected:
=======
>>>>>>> Committing original src/qt
    bool event(QEvent *event);
    bool eventFilter(QObject *object, QEvent *event);
};

#endif // ASKPASSPHRASEDIALOG_H
