//VELEA FLORIAN GRUPA315CD



#include "communication.h"
#include "util_comm.h"

#include <stdio.h>

int len_recv(int n) {
    int mask = 0;
    for(int i = 2; i < 6; i++) {
        mask = mask + (n & (1 << i));
    }
    mask = mask >>2;
    return mask;
}

/* Task 1 - The Beginning */

void send_byte_message(void)
{
    /* TODO
     * Send the encoding of the characters: R, I, C, K
     */
    send_squanch(18);
    send_squanch(9);
    send_squanch(3);
    send_squanch(11);
}


void recv_byte_message(void)
{
    /* TODO
     * Receive 5 encoded characters, decode them and print
     * them to the standard output (as characters)
     *
     * ATTENTION!: Use fprintf(stdout, ...)
     */
        for(int i= 0 ; i < 5 ; i++) {
            int c = recv_squanch();
            fprintf(stdout, "%c", (c+64));
        }

}


void comm_byte(void)
{
    /* TODO
     * Receive 10 encoded characters and send each character (the character is
     * still encoded) 2 times
     */
    for(int i = 0 ; i < 10 ; i++) {
        int c = recv_squanch();
        send_squanch(c);
        send_squanch(c);
    }
}



/* Task 2 - Waiting for the Message */

void send_message(void)
{
    /* TODO
     * Send the message: HELLOTHERE
     * - send the encoded length
     * - send each character encoded
     */
    send_squanch(235);
    send_squanch(8);
    send_squanch(5);
    send_squanch(12);
    send_squanch(12);
    send_squanch(15);
    send_squanch(20);
    send_squanch(8);
    send_squanch(5);
    send_squanch(18);
    send_squanch(5);
}


void recv_message(void)
{
    /* TODO
     * Receive a message:
     * - the first value is the encoded length
     * - length x encoded characters
     * - print each decoded character
     *
     * ATTENTION!: Use fprintf(stdout, ...)
     */
    int len = len_recv(recv_squanch());
    fprintf(stdout, "%c", ((len/10) + 48));
    fprintf(stdout, "%c", ((len%10) + 48));
    for( int i = 0 ; i < len; i++){
        int c = recv_squanch();
        fprintf(stdout, "%c", (c+64));
        }
}


void comm_message(void)
{
    /* TODO
     * Receive a message from Rick and do one of the following depending on the
     * last character from the message:
     * - 'P' - send back PICKLERICK
     * - anything else - send back VINDICATORS
     * You need to send the messages as you did at the previous tasks:
     * - encode the length and send it
     * - encode each character and send them
     */
    int len = len_recv(recv_squanch());
    for(int i = 0; i < len; i++) {
        int c = recv_squanch();

        if(i == len-1){
            if(c == 16){
                send_squanch(235);
                send_squanch(16);
                send_squanch(9);
                send_squanch(3);
                send_squanch(11);
                send_squanch(12);
                send_squanch(5);
                send_squanch(18);
                send_squanch(9);
                send_squanch(3);
                send_squanch(11);
                }
            else {
                send_squanch(237);
                send_squanch(22);
                send_squanch(9);
                send_squanch(14);
                send_squanch(4);
                send_squanch(9);
                send_squanch(3);
                send_squanch(1);
                send_squanch(20);
                send_squanch(15);
                send_squanch(18);
                send_squanch(19);
            }
        }
   }
}


/* Task 3 - In the Zone */

void send_squanch2(uint8_t c1, uint8_t c2)
{
    /* TODO
     * Steps:
     * - "merge" the character encoded in c1 and the character encoded in c2
     * - use send_squanch to send the newly formed byte
     */
    int maskc1 = 0, maskc2 = 0, merge = 0;
    for( int i = 0; i <= 6; i+=2) {
        maskc1 = c1 & 1;
        c1 = c1 >> 1;
        maskc2 = c2 & 1;
        c2 = c2 >> 1;
        merge = merge + (maskc1 << (i+1)) + (maskc2 << i);
    }
    send_squanch(merge);
}


uint8_t decode_squanch2(uint8_t c)
{
    /* TODO
     * Decode the given byte:
     * - split the two characters as in the image from ocw.cs.pub.ro
     */

    uint8_t res = -1;
    int decodedbyte = 0;
    int maskc1, maskc2, j = 0;
    for(int i = 0; i <= 3; i++) {
        maskc2 = c & 1;
        maskc1 = c & 2;
        c = c >> 2;
        j = i + 3;
        decodedbyte = decodedbyte + (maskc2 << i) + (maskc1 << j);
    }

    res = decodedbyte;

    return res;
}
