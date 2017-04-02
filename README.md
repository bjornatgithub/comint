# comint
abstract communication interface to support different fieldbus implementation

Design:

comint.h is an abstract interface. Concrete fieldbus implementation need to
implement the interfacel.

The C implementation is polimorph as a pointer to the base class comint_t can
be used to point to a sub class instance (e.g. comcan_t) and call the virtual functions of
the sub classes at runtime.

To support type safety a unique id for each concrete subclass is checked, with each function
call to the sub class. This way it is verified that the instance pointer passed is of correct type.

TODOs:
- set up corss compiler arm-gcc
- adapt data types to fixed byte types e.g. uint32_t
- finish implementation of com interfaces
- extend with furhter field bus interfaces
- introduce build options to select interfaces
- create test cases for the different interfaces
