#Cyclic Redundancy Check

divisor=(input("Enter the value of Divisor\n"))
code=(input("Enter the code\n"))
codeword=(code+'000')
print("Initial Codeword:",codeword)
int_codeword=int(codeword,2)
print("Codeword in Decimal:",int_codeword)
int_divisor=int(divisor,2)

print("Divisor in Decimal:",int_divisor   )
remainder=int_codeword%int_divisor
print("Remainder:",remainder)
bin_remainder=bin(remainder)
print(bin_remainder)
bin_remainder=(str(bin_remainder)[2:])
codeword=code+bin_remainder
print("Sent Codeword is:",codeword)
received_codeword=input("Enter the received codeword: ")
received_int_codeword=int(received_codeword,2)
print("Received Codeword in Decimal",received_int_codeword)
final_remainder=received_int_codeword%int_divisor
print("Final Remainder is:",final_remainder)

'''
def xor(a,b):
    result = []
    for i in range(1, len(b)):
        if a[i] == b[i]:
            result.append('0')
        else:
            result.append('1')
    return ''.join(result)
'''
