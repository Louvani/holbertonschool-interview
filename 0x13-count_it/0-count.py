#!/usr/bin/python3
""" 0x13. Count it! """
from requests import request


def generate_dicts(word_list):
    """ Generates the two dictionaries """
    count = {key: 0 for key in word_list}
    duplicate = {}
    for key in word_list:
        if key not in duplicate:
            duplicate[key] = 0
        duplicate[key] += 1
    return (count, duplicate)


def count_words(subreddit, word_list, after="", count={}, duplicate={}, init=0):
    """ A recursive function that queries the Reddit API,
       parses the title of all hot articles,
       and prints a sorted count of given keywords """
    if not init:
        count, duplicate = generate_dicts(word_list)

    url = "https://api.reddit.com/r/{}/hot?after={}".format(subreddit, after)
    # print(url)
    headers = {"User-Agent": "Python3"}
    response = request("GET", url, headers=headers).json()
    try:
        data = response.get('data')
        top = data.get('children')
        _after = data.get('after')

        for item in top:
            data = item.get('data')['title']
            for word in count:
                amount = data.lower().split(' ').count(word.lower())
                count[word] += amount

        if _after:
            count_words(subreddit, word_list, _after, count, duplicate, 1)
        else:
            sort_abc = sorted(count.items(), key=lambda tup: tup[::-1])
            desc = sorted(sort_abc, key=lambda tup: tup[1], reverse=True)

            for name, cnt in desc:
                cnt *= duplicate[name]
                if cnt:
                    print('{}: {}'.format(name.lower(), cnt))
    except Exception:
        return None
