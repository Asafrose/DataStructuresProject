#include "DuplicateKeyException.h"

DuplicateKeyException::DuplicateKeyException() : Exception("Key already exists")
{
}
