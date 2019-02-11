cdef extern from "rsa.h":
    long long unsigned int PollardRho(long long unsigned int n)

def py_factors(n: bytes) -> None:
    PollardRho(n)
