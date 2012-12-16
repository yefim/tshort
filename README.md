# TShort

TShort is a link shortener written in the C++ TreeFrog Framework. Users can create, edit, and remove keyword-URLs pairs, then access the long URLs via the keywords. Additionally, users can view a list of all the URLs that have been created already and see how many times a URL has been visited.

# Getting started

Install [treefrog](http://www.treefrogframework.org/documents/install).

Create a sqlite3 database with:

```
$ sqlite3/shortenerdb
$ CREATE TABLE shorturl (id INTEGER PRIMARY KEY, keyword VARCHAR(20) NOT NULL UNIQUE, url VARCHAR(200) NOT NULL, hits INTEGER, created_at TIMESTAMP, updated_at TIMESTAMP, lock_revision INTEGER);
$ .quit
```

Run qmake to compile the app.

- For Linux, run `qmake -spec linux-g++ -r "CONFIG+=release"`.
- For Mac, run `qmake -spec macx-g++ -r "CONFIG+=release"`.
- For Windows, run `qmake -spec win32-g++ -r "CONFIG+=release"`.

Run the server with `treefrog -e dev`.

Go to `http://localhost:8800/shorturl/` to view.

# Architecture

TShort is primarily built on the [treefrog](http://www.treefrogframework.org) framework, a C++ framework very similar to Rails. For the style, we used [Twitter Bootstrap](http://twitter.github.com/bootstrap/). For a database, we used sqlite3 in development and MySQL in production.
