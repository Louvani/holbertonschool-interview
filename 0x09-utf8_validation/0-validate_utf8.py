#!/usr/bin/python3
""" Checks if a given data represents a valid UTF-8 """


def bits(integer):
    """ Return: True if data is a valid UTF-8 encoding, else return False
    A character in UTF-8 can be 1 to 4 bytes long
    The data set can contain multiple characters
    The data will be represented by a list of integers """
    binary = bin(integer)[2:]
    calculate = '0' * (8 - len(binary))
    return calculate + binary


def validUTF8(data):
    """ A method that checks if a given data set represents a valid UTF-8 """
    idx = 0
    while idx < len(data):
        if bits(data[idx])[0] == '0':
            idx += 1
        elif (bits(data[idx])[:3] == '110' and idx + 1 < len(data) and
                bits(data[idx + 1])[:2] == '10'):
            idx += 2
        elif (bits(data[idx])[:4] == '1110' and idx + 2 < len(data) and
                bits(data[idx + 1])[:2] == '10' and
                bits(data[idx + 1])[:2] == '10'):
            idx += 3
        elif (bits(data[idx])[:5] == '11110' and idx + 3 < len(data) and
                bits(data[idx + 1])[:2] == '10' and
                bits(data[idx + 2])[:2] == '10' and
                bits(data[idx + 3])[:2] == '10'):
            idx += 4
        else:
            return False
    return True