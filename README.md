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

Namecoin is a decentralized key/value registration and transfer system based on Bitcoin technology (a decentralized cryptocurrency).

It can be used for multiple purposes, for example a secure and censorship resistant replacement for DNS.

Ownership of a name is based on ownership of a coin, which is in turn based on public key cryptography.  The namecoin network reaches consensus every few minutes as to which names have been reserved or updated.

There is a FAQ.md to answer some general questions.

See http://namecoin.info or http://dot-bit.org for more information.


Technical
=====================

The Bitcoin protocol is augmented with namecoin operations, to reserve, register and update names.  In addition to DNS like entries, arbitrary name/value pairs are allowed and multiple namespaces will be available.  This will include a personal handle namespace mapping handles to public keys and personal address data.

The protocol differences from bitcoin include:

* Different blockchain, port, IRC bootstrap and message header
* New transaction types: new, first-update, update
* Validation on the new transaction types
* RPC calls for managing names
* Network fees to slow down the initial rush

Please read DESIGN-namecoind.md for details.


BUILDING
======================

Building is supported on Linux, Windows and Mac. For building on windows you can use the scripts in ./contrib/easywinbuilder. Find build instructions on http://dot-bit.org.

<<<<<<< HEAD
* DNS zone conduit to allow normal DNS server to serve the .bit domain
* Firefox/chrome/... plugins
* GUI
>>>>>>> namecoin
=======
>>>>>>> Updated and cleaned the readme.
