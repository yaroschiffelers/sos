#pragma once

// SBI functions must return a pair of values in a0 and a1,
// with a0 returning an error code.
// @ref RISC-V Supervisor Binary Interface Specification - v2.0-rc1
struct sbiret
{
    long error;
    long value;
};
