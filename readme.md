#Assignment-Cpp
##Build Environment
* JetBrain Intellij Clion 2016.2 Preview
* Ubuntu 14.04
* CMake 3.5
* Gcc 4.9.3, C++ 11 (depend on [json c++ project](https://github.com/nlohmann/json))

##Features
###Sign in with user name and passwordHash
* Sign in, sign up with user name passwordHash
* Save account info to file (protected by hash algorithm)

###Account permissions
* Administrator:
  * Create another admin account
  * Open manager account
  * Remove account
  * Open manager control panel
* Manager:
  * Add, remove, modify (price, number) products
  * Manage orders (update status)
  * See simple report
* Customer:
  * Orders product
  * Track orders status