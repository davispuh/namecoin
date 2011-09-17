<<<<<<< HEAD
Bitcoin Core integration/staging tree
=====================================

http://www.bitcoin.org

Copyright (c) 2009-2013 Bitcoin Core Developers

What is Bitcoin?
----------------

Bitcoin is an experimental new digital currency that enables instant payments to
anyone, anywhere in the world. Bitcoin uses peer-to-peer technology to operate
with no central authority: managing transactions and issuing money are carried
out collectively by the network. Bitcoin Core is the name of open source
software which enables the use of this currency.

For more information, as well as an immediately useable, binary version of
the Bitcoin Core software, see http://www.bitcoin.org/en/download.

License
-------

Bitcoin Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see http://opensource.org/licenses/MIT.

Development process
-------------------

Developers work in their own trees, then submit pull requests when they think
their feature or bug fix is ready.

If it is a simple/trivial/non-controversial change, then one of the Bitcoin
development team members simply pulls it.

If it is a *more complicated or potentially controversial* change, then the patch
submitter will be asked to start a discussion (if they haven't already) on the
[mailing list](http://sourceforge.net/mailarchive/forum.php?forum_name=bitcoin-development).

The patch will be accepted if there is broad consensus that it is a good thing.
Developers should expect to rework and resubmit patches if the code doesn't
match the project's coding conventions (see [doc/coding.md](doc/coding.md)) or are
controversial.

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/bitcoin/bitcoin/tags) are created
regularly to indicate new official, stable release versions of Bitcoin.

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test. Please be patient and help out, and
remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write unit tests for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run (assuming they weren't disabled in configure) with: `make check`

Every pull request is built for both Windows and Linux on a dedicated server,
and unit and sanity tests are automatically run. The binaries produced may be
used for manual QA testing — a link to them will appear in a comment on the
pull request posted by [BitcoinPullTester](https://github.com/BitcoinPullTester). See https://github.com/TheBlueMatt/test-scripts
for the build/test scripts.

### Manual Quality Assurance (QA) Testing

Large changes should have a test plan, and should be tested by somebody other
than the developer who wrote the code.
See https://github.com/bitcoin/QA/ for how to create a test plan.
=======
Namecoin
===================

See https://dot-bit.org/ for more project information.

Namecoin is a peer to peer naming system based on bitcoin.  It is a secure and cnesorship reistant replacement for DNS.

Ownership of a name is based on ownership of a coin, which is in turn based on public key cryptography.  The namecoin network reaches consensus every few minutes as to which names have been reserved or updated.

It is envisioned that the .bit domain be used for gluing namecoin domain names into the DNS.  This can be done close to the user or even by the user.

See FAQ.md for more general information.

News
=====================

Stable releases: only releases a tag that starts with "nc", that are signed and that do not end with -rc0-9 should be considered stable.  All others are experimental.

IMPORTANT VALIDATION CHANGES at block 19200 and 24000!

* Effective at block 19200, merged mining comes into effect
* Also effective at block 19200, timetravel (2015-2016 retarget) hole is closed
* Effective at block 24000, names registered at block 12000 onward will expire after 36000 blocks instead of the current value of 12000
* Also effective at block 24000, the decline in network fees will speed up by a factor of 4

You must upgrade to the latest version nc0.3.24.\* before block 19200 or your client will start rejecting blocks and will be unable to participate in the network.

Technical
=====================

The Bitcoin protocol is augmented with namecoin operations, to reserve, register and update names.  In addition to DNS like entries, arbitrary name/value pairs are allowed and multiple namespaces will be available.  This will include a personal handle namespace mapping handles to public keys and personal address data.

The protocol differences from bitcoin include:

* Different blockchain, port, IRC bootstrap and message header
* New transaction types: new, first-update, update
* Validation on the new transaction types
* RPC calls for managing names
* Network fees to slow down the initial rush

Please read DESIGN-namecoind.md before proceeding.

BUILDING
======================

Building is only supported on Linux for now.  Follow the bitcoin build instructions.  Use "makefile.unix" - it will generate namecoind.  Usage is similar to bitcoind, plus new RPC calls for the new operations.  A GUI is on the roadmap.

RUNNING
======================

You can acquire namecoins in the usual bitcoin way, by mining or by reciving some from others.  After you have acquired some namecoins, use:

`namecoind name_new d/<name>`

This will reserve a name but not make it visible yet.  Make a note of the short hex number.  You will need it for the next step.  (Do not shut down namecoind or you will also have to supply the longer hex code below.)  Wait about 12 blocks, then issue:

`namecoind name_firstupdate d/<name> <rand> <value>`

`<rand>` is the short hex number from the previous step.  This step will make the name visible to all.

after the first update, you can do more updates with:

`namecoind name_update d/<name> <value>`

and transfer to another person:

`namecoind name_update d/<name> <value> <address>`

dump your list of names:

`namecoind name_list`

dump the global list:

`namecoind name_scan`

VALUES
===================

Values for names in the d/ namespace are JSON encoded.  The simplest value is of this form:

  {"map": {"": "10.0.0.1"}}

A [full specification](http://dot-bit.org/Domain_names) is in progress.

DNS conduits
=============

SOCKS5/Tor name resolver: See `ncproxy` in the client sub-directory.

In the near future gzip encoding of the value will be possible, but ncproxy does not support this yet.

ROADMAP
===================

* DNS zone conduit to allow normal DNS server to serve the .bit domain
* Firefox/chrome/... plugins
* GUI
>>>>>>> namecoin
