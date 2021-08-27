INSTALL
=======

See the INSTALL file for generic installation instructions.  The quick
version is:

    ./configure && make && sudo make install

USAGE
=====

You can see the program's usage statement by invoking it with --help.  A
typical invocation is:

    stress --cpu 8 --io 4 --vm 2 --vm-bytes 128M --timeout 10s

A user manual is available:

    info stress

The project home page is:

 [http://web.archive.org/web/20130520190152/http://weather.ou.edu/%7Eapw/projects/stress/](http://web.archive.org/web/20130520190152/http://weather.ou.edu/%7Eapw/projects/stress/)

PATCHES
=======

This program worked really well for the original author (Amos Waterland),
but it might not have some of the features that you want.  If you would like,
please extend the code and send Amos the patch.  Please use the context diff
format.  That is: save the original program as stress.c.orig, then make and
test your desired changes to stress.c, then run `diff -u stress.c.orig stress.c`
to produce a context diff.  Alternatively, you could try sending a pull request
on GitHub, although please note that if you are viewing this in repository form
on GitHub, you are viewing a fork by a random user with no connection to the
original project.  In any case, enjoy the program! :-D

Amos Waterland <apw@rossby.metr.ou.edu>
Norman, Oklahoma
27 Nov 2001
