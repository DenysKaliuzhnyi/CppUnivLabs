""" Denis Kaliuzhnui K-23, var 3.7.17 """
""" IMPORTANT: press "enter" on a keyboard to go to the next tact, each command has 2 tacts """

register_size = 24
byte_size = 8

Memory = {
          'IR': ' ',     # string of current command
          'R1': 0,       # registers...
          'R2': 0,
          'R3': 0,
          'R4': 0,
          'PS': '+',     # sign of current result
          'PC': 0,       # count of commands
          'TC': 0,       # current of tact
         }


def do_operation():
    operands = Memory["IR"].split()

    # PS: isnumeric method don't consider -6 as a number because of -, so we do some tricks
    val1_is_negative = 1
    val2_is_negative = 1

    if '-' in operands[2] or operands[2].isnumeric():                # operand is number that maybe is negative
        if '-' in operands[2]:                                       # negative
            val1_is_negative = -1
        val1 = int(operands[2].replace('-', '')) * val1_is_negative
    else:                                                            # operand is register
        val1 = Memory[operands[2]]

    if '-' in operands[3] or operands[3].isnumeric():                # operand is number that maybe is negative
        if '-' in operands[3]:                                       # negative
            val2_is_negative = -1
        val2 = int(operands[3].replace('-', '')) * val2_is_negative
    else:                                                            # operand is register
        val2 = Memory[operands[3]]

    if operands[0] == "add":
        Memory[operands[1]] = val1 + val2
    elif operands[0] == "sub":
        Memory[operands[1]] = val1 - val2
    elif operands[0] == "mult":
        Memory[operands[1]] = val1 * val2
    elif operands[0] == "div":
        if val2 == 0:
            raise ValueError()
        Memory[operands[1]] = val1 // val2

    if abs(Memory[operands[1]]) > 8388608:        # maxim value for 24-bit integer numbers (including negative)is 2^(23)
        raise ValueError()

    Memory['PS'] = '+' if Memory[operands[1]] >= 0 else '-'
    Memory['TC'] += 1


def to_bin(num):                                  # return string of number in base 2
    s = ''
    for _ in range(register_size):
        s = str(num % 2) + s
        num //= 2
    return s


def to_byte(num):                                 # return string of number in base 2 with splitting by '|'
    s = to_bin(num)
    s_separated = s[0:byte_size]
    for i in range(1, register_size // byte_size):
        s_separated = s_separated + '|' + s[i * byte_size:(i + 1) * byte_size]
    return s_separated


def print_info():
    print('IR:', Memory['IR'])
    print('R1:',  to_byte(Memory['R1']))
    print('R2:',  to_byte(Memory['R2']))
    print('R3:',  to_byte(Memory['R3']))
    print('R4:',  to_byte(Memory['R4']))
    print('PS:', Memory['PS'])
    print('PC:', Memory['PC'])
    print('TC:', Memory['TC'])
    input('')


# PS: in last operation (add R4 8388608 + 1) error expected (because of overflow)
def read():
    fin = open('input.txt', 'r', encoding="utf8")
    for line in fin:
        Memory['IR'] = line.strip()
        Memory['TC'] = 1
        Memory['PC'] += 1
        print_info()             # first tact
        do_operation()
        print_info()             # second tact


if __name__ == '__main__':
    try:
        read()
    except ValueError:
        print(ValueError.__doc__)
