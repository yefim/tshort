# tshort

# Getting started

Install [treefrog](http://www.treefrogframework.org/documents/install).

Run qmake to compile the app.

- For Linux, run `qmake -spec linux-g++ -r "CONFIG+=release"`.
- For Mac, run `qmake -spec macx-g++ -r "CONFIG+=release"`.
- For Windows, run `qmake -spec win32-g++ -r "CONFIG+=release"`.

Run the server with `treefrog -e dev`.

Go to `http://localhost:8800/shorturl/` to view.

