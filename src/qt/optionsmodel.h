<<<<<<< HEAD
// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

=======
>>>>>>> Committing original src/qt
#ifndef OPTIONSMODEL_H
#define OPTIONSMODEL_H

#include <QAbstractListModel>

<<<<<<< HEAD
QT_BEGIN_NAMESPACE
class QNetworkProxy;
QT_END_NAMESPACE

=======
>>>>>>> Committing original src/qt
/** Interface from Qt to configuration data structure for Bitcoin client.
   To Qt, the options are presented as a list with the different options
   laid out vertically.
   This can be changed to a tree once the settings become sufficiently
   complex.
 */
class OptionsModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit OptionsModel(QObject *parent = 0);

    enum OptionID {
<<<<<<< HEAD
        StartAtStartup,         // bool
        MinimizeToTray,         // bool
        MapPortUPnP,            // bool
        MinimizeOnClose,        // bool
        ProxyUse,               // bool
        ProxyIP,                // QString
        ProxyPort,              // int
        ProxySocksVersion,      // int
        Fee,                    // qint64
        DisplayUnit,            // BitcoinUnits::Unit
        DisplayAddresses,       // bool
        Language,               // QString
        CoinControlFeatures,    // bool
        ThreadsScriptVerif,     // int
        DatabaseCache,          // int
        SpendZeroConfChange,    // bool
=======
        StartAtStartup,    // bool
        MinimizeToTray,    // bool
        MapPortUPnP,       // bool
        MinimizeOnClose,   // bool
        ProxyUse,          // bool
        ProxyIP,           // QString
        ProxyPort,         // int
        ProxySocksVersion, // int
        Fee,               // qint64
        DisplayUnit,       // BitcoinUnits::Unit
        DisplayAddresses,  // bool
        Language,          // QString
>>>>>>> Committing original src/qt
        OptionIDRowCount,
    };

    void Init();
    void Reset();

<<<<<<< HEAD
=======
    /* Migrate settings from wallet.dat after app initialization */
    bool Upgrade(); /* returns true if settings upgraded */

>>>>>>> Committing original src/qt
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);

    /* Explicit getters */
<<<<<<< HEAD
=======
    qint64 getTransactionFee();
>>>>>>> Committing original src/qt
    bool getMinimizeToTray() { return fMinimizeToTray; }
    bool getMinimizeOnClose() { return fMinimizeOnClose; }
    int getDisplayUnit() { return nDisplayUnit; }
    bool getDisplayAddresses() { return bDisplayAddresses; }
<<<<<<< HEAD
    bool getProxySettings(QNetworkProxy& proxy) const;
    bool getCoinControlFeatures() { return fCoinControlFeatures; }
    const QString& getOverriddenByCommandLine() { return strOverriddenByCommandLine; }

    /* Restart flag helper */
    void setRestartRequired(bool fRequired);
    bool isRestartRequired();

private:
    /* Qt-only settings */
    bool fMinimizeToTray;
    bool fMinimizeOnClose;
    QString language;
    int nDisplayUnit;
    bool bDisplayAddresses;
    bool fCoinControlFeatures;
    /* settings that were overriden by command-line */
    QString strOverriddenByCommandLine;

signals:
    void displayUnitChanged(int unit);
    void transactionFeeChanged(qint64);
    void coinControlFeaturesChanged(bool);
=======
    QString getLanguage() { return language; }

private:
    int nDisplayUnit;
    bool bDisplayAddresses;
    bool fMinimizeToTray;
    bool fMinimizeOnClose;
    QString language;

signals:
    void displayUnitChanged(int unit);
>>>>>>> Committing original src/qt
};

#endif // OPTIONSMODEL_H
