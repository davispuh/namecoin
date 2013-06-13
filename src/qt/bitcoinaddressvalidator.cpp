<<<<<<< HEAD
// Copyright (c) 2011-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "bitcoinaddressvalidator.h"

#include "base58.h"

=======
#include "bitcoinaddressvalidator.h"

>>>>>>> Committing original src/qt
/* Base58 characters are:
     "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz"

  This is:
  - All numbers except for '0'
  - All upper-case letters except for 'I' and 'O'
  - All lower-case letters except for 'l'
<<<<<<< HEAD
*/

BitcoinAddressEntryValidator::BitcoinAddressEntryValidator(QObject *parent) :
=======

  User friendly Base58 input can map
  - 'l' and 'I' to '1'
  - '0' and 'O' to 'o'
*/

<<<<<<< HEAD
BitcoinAddressValidator::BitcoinAddressValidator(QObject *parent) :
>>>>>>> Committing original src/qt
    QValidator(parent)
=======
BitcoinAddressValidator::BitcoinAddressValidator(QObject *parent, bool fAllowEmpty) :
    QValidator(parent), allowEmpty(fAllowEmpty)
>>>>>>> Added GUI tab for name_* commands. Version 0.3.60.
{
}

<<<<<<< HEAD
QValidator::State BitcoinAddressEntryValidator::validate(QString &input, int &pos) const
{
    Q_UNUSED(pos);

    // Empty address is "intermediate" input
    if (input.isEmpty())
        return QValidator::Intermediate;

    // Correction
    for (int idx = 0; idx < input.size();)
=======
QValidator::State BitcoinAddressValidator::validate(QString &input, int &pos) const
{
    // Correction
    for(int idx=0; idx<input.size();)
>>>>>>> Committing original src/qt
    {
        bool removeChar = false;
        QChar ch = input.at(idx);
        // Corrections made are very conservative on purpose, to avoid
        // users unexpectedly getting away with typos that would normally
        // be detected, and thus sending to the wrong address.
        switch(ch.unicode())
        {
        // Qt categorizes these as "Other_Format" not "Separator_Space"
        case 0x200B: // ZERO WIDTH SPACE
        case 0xFEFF: // ZERO WIDTH NO-BREAK SPACE
            removeChar = true;
            break;
        default:
            break;
        }
<<<<<<< HEAD

        // Remove whitespace
        if (ch.isSpace())
            removeChar = true;

        // To next character
        if (removeChar)
=======
        // Remove whitespace
        if(ch.isSpace())
            removeChar = true;
        // To next character
        if(removeChar)
>>>>>>> Committing original src/qt
            input.remove(idx, 1);
        else
            ++idx;
    }

    // Validation
    QValidator::State state = QValidator::Acceptable;
<<<<<<< HEAD
    for (int idx = 0; idx < input.size(); ++idx)
    {
        int ch = input.at(idx).unicode();

        if (((ch >= '0' && ch<='9') ||
            (ch >= 'a' && ch<='z') ||
            (ch >= 'A' && ch<='Z')) &&
            ch != 'l' && ch != 'I' && ch != '0' && ch != 'O')
=======
    for(int idx=0; idx<input.size(); ++idx)
    {
        int ch = input.at(idx).unicode();

        if(((ch >= '0' && ch<='9') ||
           (ch >= 'a' && ch<='z') ||
           (ch >= 'A' && ch<='Z')) &&
           ch != 'l' && ch != 'I' && ch != '0' && ch != 'O')
>>>>>>> Committing original src/qt
        {
            // Alphanumeric and not a 'forbidden' character
        }
        else
        {
            state = QValidator::Invalid;
        }
    }

<<<<<<< HEAD
<<<<<<< HEAD
    return state;
}

BitcoinAddressCheckValidator::BitcoinAddressCheckValidator(QObject *parent) :
    QValidator(parent)
{
}

QValidator::State BitcoinAddressCheckValidator::validate(QString &input, int &pos) const
{
    Q_UNUSED(pos);
    // Validate the passed Bitcoin address
    CBitcoinAddress addr(input.toStdString());
    if (addr.IsValid())
        return QValidator::Acceptable;

    return QValidator::Invalid;
=======
    // Empty address is "intermediate" input
    if(input.isEmpty())
=======
    if (input.isEmpty() && !allowEmpty)
>>>>>>> Added GUI tab for name_* commands. Version 0.3.60.
    {
        // Empty address is "intermediate" input
        state = QValidator::Intermediate;
    }

    return state;
>>>>>>> Committing original src/qt
}
