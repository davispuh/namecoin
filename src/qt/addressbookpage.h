<<<<<<< HEAD
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

=======
>>>>>>> Committing original src/qt
#ifndef ADDRESSBOOKPAGE_H
#define ADDRESSBOOKPAGE_H

#include <QDialog>

<<<<<<< HEAD
class AddressTableModel;
class OptionsModel;

namespace Ui {
    class AddressBookPage;
}

QT_BEGIN_NAMESPACE
class QItemSelection;
class QMenu;
class QModelIndex;
class QSortFilterProxyModel;
class QTableView;
=======
namespace Ui {
    class AddressBookPage;
}
class AddressTableModel;
class OptionsModel;

QT_BEGIN_NAMESPACE
class QTableView;
class QItemSelection;
class QSortFilterProxyModel;
class QMenu;
class QModelIndex;
>>>>>>> Committing original src/qt
QT_END_NAMESPACE

/** Widget that shows a list of sending or receiving addresses.
  */
class AddressBookPage : public QDialog
{
    Q_OBJECT

public:
    enum Tabs {
        SendingTab = 0,
        ReceivingTab = 1
    };

    enum Mode {
<<<<<<< HEAD
        ForSelection, /**< Open address book to pick address */
        ForEditing  /**< Open address book for editing */
    };

    explicit AddressBookPage(Mode mode, Tabs tab, QWidget *parent);
    ~AddressBookPage();

    void setModel(AddressTableModel *model);
=======
        ForSending, /**< Open address book to pick address for sending */
        ForEditing  /**< Open address book for editing */
    };

    explicit AddressBookPage(Mode mode, Tabs tab, QWidget *parent = 0);
    ~AddressBookPage();

    void setModel(AddressTableModel *model);
    void setOptionsModel(OptionsModel *optionsModel);
>>>>>>> Committing original src/qt
    const QString &getReturnValue() const { return returnValue; }

public slots:
    void done(int retval);
    void exportClicked();

private:
    Ui::AddressBookPage *ui;
    AddressTableModel *model;
<<<<<<< HEAD
=======
    OptionsModel *optionsModel;
>>>>>>> Committing original src/qt
    Mode mode;
    Tabs tab;
    QString returnValue;
    QSortFilterProxyModel *proxyModel;
    QMenu *contextMenu;
    QAction *deleteAction; // to be able to explicitly disable it
    QString newAddressToSelect;

private slots:
    /** Delete currently selected address entry */
    void on_deleteButton_clicked();
    /** Create a new address for receiving coins and / or add a new address book entry */
    void on_newAddressButton_clicked();
    /** Copy address of currently selected address entry to clipboard */
<<<<<<< HEAD
    void on_copyAddress_clicked();
<<<<<<< HEAD
=======
=======
    void on_copyToClipboard_clicked();
>>>>>>> Commiting my updates that turn namecoind into namecoin-qt.
    /** Open the sign message tab in the Sign/Verify Message dialog with currently selected address */
    void on_signMessage_clicked();
    /** Open the verify message tab in the Sign/Verify Message dialog with currently selected address */
    void on_verifyMessage_clicked();
    /** Open send coins dialog for currently selected address (no button) */
    void onSendCoins_clicked();
    /** Generate a QR Code from the currently selected address */
    void on_showQRCode_clicked();
>>>>>>> Committing original src/qt
    /** Copy label of currently selected address entry to clipboard (no button) */
    void onCopyLabelAction();
    /** Edit currently selected address entry (no button) */
    void onEditAction();

    /** Set button states based on selected tab and selection */
    void selectionChanged();
    /** Spawn contextual menu (right mouse menu) for address book entry */
    void contextualMenu(const QPoint &point);
    /** New entry/entries were added to address table */
    void selectNewAddress(const QModelIndex &parent, int begin, int /*end*/);

signals:
<<<<<<< HEAD
=======
    void signMessage(QString addr);
    void verifyMessage(QString addr);
>>>>>>> Committing original src/qt
    void sendCoins(QString addr);
};

#endif // ADDRESSBOOKPAGE_H
