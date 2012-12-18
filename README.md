# TShort (live at [yefim.org](http://yefim.org))

TShort is a link shortener written in the C++ TreeFrog Framework. Users can create, edit, and remove keyword-URLs pairs, then access the long URLs via the keywords. Additionally, users can view a list of all the URLs that have been created already and see how many times a URL has been visited.

# Getting started

Install [treefrog](http://www.treefrogframework.org/documents/install).

Create a sqlite3 database with:

```
$ mkdir db
$ sqlite3 db/shortenerdb < shortenerdb.sql
```

Run qmake to compile the app.

- For Linux, run `qmake -spec linux-g++ -r "CONFIG+=release"`.
- For Mac, run `qmake -spec macx-g++ -r "CONFIG+=release"`.
- For Windows, run `qmake -spec win32-g++ -r "CONFIG+=release"`.

Run `make`

Run the server with `treefrog -e dev`.

Go to [localhost:8800/](http://localhost:8800) to view.

# Architecture

TShort is primarily built on the [treefrog](http://www.treefrogframework.org) framework, a C++ framework very similar to Rails. For the style, we used [Twitter Bootstrap](http://twitter.github.com/bootstrap/). For a database, we used sqlite3 in development and MySQL in production.

# Contributors

- Geoffrey Vedernikoff <veg@seas.upenn.edu>
- Kai Ninomiya <kainino@seas.upenn.edu>
- Ceasar Bautista <ceasarb@seas.upenn.edu>
