# basic_binary_functions-games

Part 1 - Bits & Pieces

Part 1.1 - Bit by Bit

get_bit întoarce 1 dacă bitul este activat, altfel întoarce 0.

flip_bit întoarce numărul cu bitul i răsturnat ( dacă bitul i este 0 îl face 1 sau dacă este 0 este 1)


!!! de reținut că aceste funcții (flip_bit, activate_bit și clear_bit) nu dau tot punctajul dacă la shiftări nu lucrăm cu numere pe 64 de biți // ex: 1 este declarat în int(32 biți) și a trebuit să-l declarăm în usigned long(64 biți)


activate_bit întoarce numărul cu bitul i activat

clear_bit întoarce numărul cu bitul i dezactivat


Part 1.2 - One gate to rule them all

and_gate, not_gate, or_gate și xor_gate au fost făcute cu ajutorul funcției nand_gate.


Part 1.3 - Just Carry the Bit

full_adder face suma doar pe mulțimea 0 și 1. Fiind adunare pe biți, a trebuit să encodăm suma și carry-ul ( am creat un alt byte și am pus pe prima poziție suma și pe al doilea am pus carry-ul)

ripple_carry_adder face suma dintre 2 numere naturale.Am luat primul bit de la fiecare număr și l-am introdus în full_adder cu prima intrare a carry-ului = 0. Am decodat rezultatul din full_adder și am adăugat corespunzător sumei și carry-ului bitul nevoit.


	Part 2 -Shut up Morty!

Am declarat o funcție (len_recv) pentru a afla lungimea sirului de caractere mai ușor în problemele viitoare.


Part 2.1 - The beginning

am folosit funcțiile definite in util_comm.c pentru a rezolva problemele send_byte_message ,comm_byte recv_byte_message și am folosit codul ascii unde mai era nevoie pentru a decoda squanch-ul primit de la Rick.


Part 2.2 -Waiting for the Message

send_message - primul send_squanch este lungimea șirului de caractere, restul este mesajul cerut.

recv_message - am folosit funcția definită la început (len_recv) pentru a afla lungimea mesajului, în rest problema este la fel ca la recv_byte_message.

comm_message - am folosit funcția definită la început (len_recv) pentru a afla lungimea mesajului, am verificat dacă ultimul caracter este P și am întors rezultatul dorit.


Part 2.3 - In the Zone

send_squanch2 - am folosit instrucțiunile din imagine și lucrul pe măști pentru ajunge la rezulatul dorit. Am făcut măști pentru a muta biții din c1 și c2 și le-am pus pe pozițiile dorite prin shiftare.
recv_squanch2 - cu ajutorul imaginii  de pe ocw am decodat și restul problemei este de asemănător cu cel precedent.

	Part 3 - Toss a coin to your Witcher

Part 3.1 - Axii

find_spell - printr-un for am trecut print toți biții din memorie și odată ce găseam 5 biți activi consecutivi shiftam cu i poziții în stânga ca să avem primii 16 biți fix spell-ul.

find_key - același lucru ca la find_spell, doar că shiftam cu i-18 poziții când găsește 3 biți activi consecutivi.

decrypt_spell este doar un xor între spell și key.


Part 3.2 - Sword Play

choose_sword - În primul rând am verificat dacă există un număr par sau impar de biți activi in valoarea dată, în funcție de rezultat am rezolvat ecuațiile date în enunț. Pentru a crea sabia am luat rezultatul din ecuațiile rezolvate anterior și le-am concatenat cu tipul de sabie dorit prin shifăti.

Part 3.3 - The Witcher Trials


trial_of_the_grasses - este deja destul de explicit încă din enunț

trial_of_forrest_eyes - am folosit for pentru a trece prin fiecare bit și am creat condiții specifice pentru a afla ce map este, ca în cerință. 

trial_of_the_dreams - am folosit un for în for. Primul for trece prin toți biții mapei până când găsește unul activ, după se intră în al doilea for ce măsoară distanța până la următorul bit activ.




