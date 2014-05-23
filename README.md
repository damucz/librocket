librocket
=========

C++ user interface middleware based on HTML and CSS, for Marmalade.

[Website](http://librocket.com/) & [Documentation](http://librocket.com/wiki/documentation).

* fonts
* windows
* scrollbars
* [data grids](http://librocket.com/wiki/documentation/tutorials/Datagrid)
* [trees](http://librocket.com/wiki/documentation/tutorials/DatagridTree)
* [localisation](http://librocket.com/wiki/documentation/Localisation)
* form controls (edit boxes, checkboxes, radios, buttons, select boxes, buttons)
* you can add your own elements (components)
* or even styles and visual decorators
* dynamic data representation (model, view, controller)
* visual debugger
* event system
* and possible scripting language (Python - not available ATM)

These sources contain Marmalade project and sample showcase.

Marmalade project
-----------------

1. Include _libproject_ (static libs) or _libroject-source_ into your _subprojects_ in mkb.
2. Then you should register I/O objects into the lib (check src/test.cpp)
3. Call Update and Render on context in the app loop

Showcase
--------

Open, compile and run _librockettest.mkb_. There is a movable window and some sample form controls.
