#!/usr/bin/python3
"""stats"""
import sys


def log_parsing():
    """Log parsing"""
    c = size = 0
    counter = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0,
               "404": 0, "405": 0, "500": 0}

    try:
        for line in sys.stdin:
            c += 1
            split = line.split(" ")
            try:
                status = split[-2]
                size += int(split[-1])
                if status in counter:
                    counter[status] += 1
            except Exception:
                pass
            if c % 10 == 0:
                helper(counter, size)
        else:
            helper(counter, size)
    except (KeyboardInterrupt, SystemExit):
        helper(counter, size)
        raise

def helper(statCount, fileSize):
    print("File size: {}".format(fileSize))
    for key in sorted(statCount.keys()):
        if statCount[key] == 0:
            continue
        print("{}: {}".format(key, statCount[key]))

if __name__ == "__main__":
    log_parsing()