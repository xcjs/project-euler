xcjs/project-euler
==================

Vist <http://projecteuler.net> for more information.

C++ Answers to Project Euler

Introduction
------------

I am approaching this project from the direction of a .NET/Web Developer with
interests in what I consider lower level, or "true", programming environments.

I have several personal goals tied into creating this repository and working on
its accompanying codebase:

* I am challenging myself to learn the C++ programming language and wish to
document my progress
* I am challenging myself to learn mathematics that exceed my received
education
* I am hoping that this project attests to my ability to program, my
capability to teach myself new skills, and my self-motivation

Spoilers Ahead
--------------

My intent in creating this repository lies in __not__ revealing answers to 
anyone taking part in Project Euler. I am in no way trying to claim that
I have the best answers, but in the spirit of challenging oneself, please do
not refer to this codebase as a means to an end.

However, if you have already solved the problems that can be found here and
wish to compare answers, by all means please feel free to look. That's another
reason why this repository remains public.

Organization and Direction
--------------------------

Currently each Project Euler solution can be found separated by a single file. 
Each file is numerically named after the problem it solves.

This is because I am starting the project without introducing much complexity. 
As I learn more of C++, I plan on introducing a more reusable object-oriented 
structure with code reusability and combining all the classes under a single 
application.

I will probably also include a Make script to manage building the project(s).

Environment and Building
------------------------

I have an existing interest in code portability and cross-platform development. 
To facilitate this, I am using g++ and the standard C++ library. Some 
archtectural decisions are also being influenced by the 32/64 bit architecture 
divide.

Currently, all solutions should compile on either address width on any 
architecture that supports GCC (the GNU Compiler Collection) and the standard 
library.

Currently, I am able to test the code on the following platforms:

* Windows 7, x86_64
* Ubuntu Linux, x86_64
* Ubuntu Linux,  32 bit armhf on an ARMv7 OMAP4 CPU (Ubuntu using an Android
Linux kernel on a DROID 4 mobile phone device)

If there are any difficulties with building any of the solutions, please create an
issue, and I will solve it as soon as possible.
