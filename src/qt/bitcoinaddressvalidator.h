<<<<<<< HEAD
// Copyright (c) 2011-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

=======
>>>>>>> Committing original src/qt
#ifndef BITCOINADDRESSVALIDATOR_H
#define BITCOINADDRESSVALIDATOR_H

#include <QValidator>

<<<<<<< HEAD
/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class BitcoinAddressEntryValidator : public QValidator
=======
/** Base48 entry widget validator.
   Corrects near-miss characters and refuses characters that are no part of base48.
 */
class BitcoinAddressValidator : public QValidator
>>>>>>> Committing original src/qt
{
    Q_OBJECT

public:
<<<<<<< HEAD
    explicit BitcoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Bitcoin address widget validator, checks for a valid bitcoin address.
 */
class BitcoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BitcoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
=======
    explicit BitcoinAddressValidator(QObject *parent = 0);

    State validate(QString &input, int &pos) const;

    static const int MaxAddressLength = 35;
>>>>>>> Committing original src/qt
};

#endif // BITCOINADDRESSVALIDATOR_H
