#pragma once

// SBI functions must return a pair of values in a0 and a1,
// with a0 returning an error code.
struct sbiret
{
    long error;
    long value;
};
