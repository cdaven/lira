# Lira

Lira indexed and organized all your MP3 songs, and you could play them through Winamp.

This was my contribution to Datormagazin's big programming competition in 2003 ("Datormagazins Stora Programmeringstävling 2003"). The winners were revealed in magazine #2, 2004. (I did not get any kind of prize or honorary mention.)

I started working on this just days after Apple released iTunes for Windows on October 16, 2003. You could say this is my iTunes clone.

Lira was built using Borland C++Builder, and I have no idea how to compile it nowadays.

This was not my first C++ project, but as it happened, it would be my last (as of 2023).

## Design Overview

[guimain.cpp](https://github.com/cdaven/lira/blob/main/gui/guimain.cpp) is where the main application form is created, and also where I initialize the [Mediator](https://github.com/cdaven/lira/blob/main/Mediator.cpp) object,
that is used for communication between objects without tight coupling (see [Mediator Pattern](https://en.wikipedia.org/wiki/Mediator_pattern)).

It would seem I store the index of all MP3 songs in [a flat-file database](https://github.com/cdaven/lira/blob/main/database/ConcreteDatabaseEngine.cpp).

---

Original README in Swedish here: https://github.com/cdaven/lira/tree/main/installer#readme
