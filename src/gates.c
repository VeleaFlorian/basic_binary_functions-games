//VELEA FLORIAN GRUPA315CD



#include "gates.h"

#include <stdio.h>
#include <assert.h>

/* Task 1 - Bit by Bit */

uint8_t get_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint8_t res = -1;

    /* TODO
     *
     * "res" should be 1 if the bit is active, else 0
     */
    uint64_t x = nr & 1<<i;
        if(x >= 1)
            res = 1;
        else
            res = 0;
    return res;
}


uint64_t flip_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint64_t res = -1;

    /* TODO
     *
     * Return the "nr" with the ith bit flipped
     */



    res = ((unsigned long)1 << i) ^ nr;

    return res;


}


uint64_t activate_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint64_t res = 0xFF;

    /* TODO
     *
     * Return the "nr" with the ith bit "1"
     */

res = nr | (unsigned long)1 << i;
    return res;
}


uint64_t clear_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint64_t res = -1;

    /* TODO
     *
     * Return the "nr" with the ith bit "0"
     */
 res = nr & ~((unsigned long)1 << i);

    return res;
}


/* Task 2 - One Gate to Rule Them All */

uint8_t nand_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    return !(a & b);
}


uint8_t and_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    uint8_t res = -1;

    /* TODO - Use the nand gate to implement the and gate */

    res = nand_gate(nand_gate(a, b), nand_gate(a, b));

    return res;
}


uint8_t not_gate(uint8_t a)
{
    assert (a == 0 || a == 1);

    uint8_t res = -1;

    /* TODO - Use the nand gate to implement the not gate */

    res = nand_gate(a, a);
    return res;
}


uint8_t or_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    uint8_t res = -1;

    /* TODO - Use the previously defined gates to implement the or gate */

    res = nand_gate(not_gate(a), not_gate(b));
    return res;
}


uint8_t xor_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    uint8_t res = -1;

    /* TODO - Use the previously defined gates to implement the xor gate */
    res = nand_gate( nand_gate(not_gate(a), b), nand_gate(not_gate(b), a));
    return res;
}


/* Task 3 - Just Carry the Bit */

uint8_t full_adder(uint8_t a, uint8_t b, uint8_t c)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);
    assert (c == 0 || c == 1);

    uint8_t res = -1;

    /* TODO - implement the full_adder using the previous gates
     * Since the full_adder needs to provide 2 results, you should
     * encode the sum bit and the carry bit in one byte - you can encode
     * it in whatever way you like
     */
    uint64_t sum = xor_gate(xor_gate(a, b), c);
    c = or_gate(and_gate(a, b), and_gate(xor_gate(a, b), c));
    res = sum + (c << 1);
    return res;
}


uint64_t ripple_carry_adder(uint64_t a, uint64_t b)
{
    double res = 0;

    /* TODO
     * Use the full_adder to implement the ripple carry adder
     * If there is ANY overflow while adding "a" and "b" then the
     * result should be 0
     */
    uint64_t c = 0, maska = 0, maskb = 0, i, a1 = 0, b1 = 0;



        for(i = 0; i < 64; i++) {
            maska = (unsigned long)1 << i;
            maskb = (unsigned long)1 << i;
            a1 = a & maska;
            a1 = a1 >> i;
            b1 = b & maskb;
            b1 = b1 >> i;
            res = res + ((full_adder(a1,b1,c) & (unsigned long)1) << i);
            c = full_adder(a1, b1, c) >> (unsigned long)1;

            if(res > UINT64_MAX)
                return 0;
        }
            return res;
    }



