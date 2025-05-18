It is a test of the possiblity and limitation of use of C++20 modules with QObject-inheriting Qt classes.

A simple class is defined and exported from a module and imported into cpp-file containing the definition of 
MainWindow class (created by Qt Creator wizard from the default template). 

As this test shows, it is possible to import and use a module-defined class with a QObject inheritor. 

The only big limitation is that the macro `Q_OBJECT`, which is used by moc, seems to be incompatible with modules, as 
macros are (the real incompatibility is not tested yet). So for this test a forward declaration was used, a 
pointer to an incomplete type was stored in MainWindow class, and a member function used a reference to that
incomplete type as a parameter. `import TestModule;` statement was used in a corresponding .cpp file to implement
that member function and intialize/use/destroy the pointer. 

Currently the only configuration on which it was tested is Windows 10, Qt 6.8.1 and MSVC2022 kit. There were some
troubles with enabling modules even with MSVC, so CMakeLists.txt contains some MSVC-specific stuff.  
