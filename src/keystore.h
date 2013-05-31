// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_KEYSTORE_H
#define BITCOIN_KEYSTORE_H

<<<<<<< HEAD
#include "key.h"
#include "sync.h"

#include <boost/signals2/signal.hpp>

class CScript;

/** A virtual base class for key stores */
class CKeyStore
{
protected:
    mutable CCriticalSection cs_KeyStore;

public:
    virtual ~CKeyStore() {}

    // Add a key to the store.
    virtual bool AddKeyPubKey(const CKey &key, const CPubKey &pubkey) =0;
    virtual bool AddKey(const CKey &key);

    // Check whether a key corresponding to a given address is present in the store.
    virtual bool HaveKey(const CKeyID &address) const =0;
    virtual bool GetKey(const CKeyID &address, CKey& keyOut) const =0;
    virtual void GetKeys(std::set<CKeyID> &setAddress) const =0;
    virtual bool GetPubKey(const CKeyID &address, CPubKey& vchPubKeyOut) const;

    // Support for BIP 0013 : see https://en.bitcoin.it/wiki/BIP_0013
    virtual bool AddCScript(const CScript& redeemScript) =0;
    virtual bool HaveCScript(const CScriptID &hash) const =0;
    virtual bool GetCScript(const CScriptID &hash, CScript& redeemScriptOut) const =0;
};

typedef std::map<CKeyID, CKey> KeyMap;
typedef std::map<CScriptID, CScript > ScriptMap;

/** Basic key store, that keeps keys in an address->secret map */
class CBasicKeyStore : public CKeyStore
{
protected:
    KeyMap mapKeys;
    ScriptMap mapScripts;

public:
    bool AddKeyPubKey(const CKey& key, const CPubKey &pubkey);
    bool HaveKey(const CKeyID &address) const
    {
        bool result;
        {
            LOCK(cs_KeyStore);
            result = (mapKeys.count(address) > 0);
        }
        return result;
    }
    void GetKeys(std::set<CKeyID> &setAddress) const
    {
        setAddress.clear();
        {
            LOCK(cs_KeyStore);
            KeyMap::const_iterator mi = mapKeys.begin();
            while (mi != mapKeys.end())
            {
                setAddress.insert((*mi).first);
                mi++;
            }
        }
    }
    bool GetKey(const CKeyID &address, CKey &keyOut) const
    {
        {
            LOCK(cs_KeyStore);
            KeyMap::const_iterator mi = mapKeys.find(address);
            if (mi != mapKeys.end())
            {
                keyOut = mi->second;
                return true;
            }
=======
#include <boost/signals2/signal.hpp>
#include <boost/signals2/last_value.hpp>
#include "crypter.h"

// Currently CPrivKey is just std::vector<unsigned char> (with secure_allocator)
typedef std::map<std::vector<unsigned char>, CPrivKey> KeyMap;
typedef std::map<std::vector<unsigned char>, std::vector<unsigned char> > CryptedKeyMap;

class CKeyStore
{
private:
    KeyMap mapKeys;
    CryptedKeyMap mapCryptedKeys;

    CKeyingMaterial vMasterKey;

    // if fUseCrypto is true, mapKeys must be empty
    // if fUseCrypto is false, vMasterKey must be empty
    bool fUseCrypto;

public:

    CKeyStore()
        : fUseCrypto(false)
    {
    }
    
    virtual ~CKeyStore()
    {
    }

    void DebugPrint()
    {
        printf("mapKeys.size() = %d\n",         mapKeys.size());
        printf("mapCryptedKeys.size() = %d\n",  mapCryptedKeys.size());
    }

    mutable CCriticalSection cs_mapKeys;

    virtual bool AddKey(const CKey& key);
    virtual bool AddCryptedKey(const std::vector<unsigned char> &vchPubKey, const std::vector<unsigned char> &vchCryptedSecret);

    virtual bool AddAddress(const uint160& hash160);

    virtual bool HaveKey(const std::vector<unsigned char> &vchPubKey) const
    {
        CRITICAL_BLOCK(cs_mapKeys)
        {
            if (IsCrypted())
                return (mapCryptedKeys.count(vchPubKey) > 0);
            else
                return (mapKeys.count(vchPubKey) > 0);
        }
    }

    virtual bool GetPrivKey(const std::vector<unsigned char> &vchPubKey, CPrivKey& keyOut) const
    {
        CRITICAL_BLOCK(cs_mapKeys)
        {
            if (!IsCrypted())
            {
                std::map<std::vector<unsigned char>, CPrivKey>::const_iterator mi = mapKeys.find(vchPubKey);
                if (mi != mapKeys.end())
                {
                    keyOut = (*mi).second;
                    return true;
                }
            }
            else
            {
                CryptedKeyMap::const_iterator mi = mapCryptedKeys.find(vchPubKey);
                if (mi != mapCryptedKeys.end())
                {
                    const std::vector<unsigned char> &vchCryptedSecret = (*mi).second;
                    if (!DecryptSecret(vMasterKey, vchCryptedSecret, Hash(vchPubKey.begin(), vchPubKey.end()), keyOut))
                        return false;
                    if (keyOut.size() != CSECRET_SIZE)
                        return false;
                    return true;
                }
            }
            return false;
>>>>>>> Commiting my updates that turn namecoind into namecoin-qt.
        }
    }
<<<<<<< HEAD
    virtual bool AddCScript(const CScript& redeemScript);
    virtual bool HaveCScript(const CScriptID &hash) const;
    virtual bool GetCScript(const CScriptID &hash, CScript& redeemScriptOut) const;
=======

    std::vector<unsigned char> GenerateNewKey();
    
    bool IsCrypted() const
    {
        return fUseCrypto;
    }

    bool IsLocked() const
    {
        if (!IsCrypted())
            return false;
        bool result;
        CRITICAL_BLOCK(cs_mapKeys)
            result = vMasterKey.empty();
        return result;
    }

    bool Lock();

#ifdef GUI
    boost::signals2::signal<void (CKeyStore* wallet)> NotifyStatusChanged;
#endif

protected:
    bool SetCrypted();

    // will encrypt previously unencrypted keys
    bool EncryptKeys(CKeyingMaterial& vMasterKeyIn);

    virtual bool Unlock(const CKeyingMaterial& vMasterKeyIn); 
>>>>>>> Commiting my updates that turn namecoind into namecoin-qt.
};

typedef std::vector<unsigned char, secure_allocator<unsigned char> > CKeyingMaterial;
typedef std::map<CKeyID, std::pair<CPubKey, std::vector<unsigned char> > > CryptedKeyMap;

#endif
