import random

def playATurn(limit, cards):
    sum = 0
    # tmp = []
    while True:
        val = cards.pop()
        # tmp.append(val)
        if (val > 9):
            val = 10
            sum+= val

        elif (val == 1):
            if (sum > limit - 11) and (sum + 11 <= 21):
                sum+= 11
            elif (sum + 10 == 21):
                sum+= 10
            else:
                sum+= 1

        else:
            sum+= val

        if (sum >= limit): break
    # print(tmp, sum)
    return sum

def playGame(playerLimit, dealerLimit):
    cards = [x for x in range(1, 14)]
    cards*= 4
    random.shuffle(cards)
    playerScore = playATurn(playerLimit, cards)
    dealerScore = playATurn(dealerLimit, cards)
    if (playerScore > 21) and (dealerScore > 21): 
        return 0
    if (dealerScore > 21):
        return 1
    if (playerScore > 21):
        return -1
    if (playerScore > dealerScore):
        return 1
    elif (playerScore == dealerScore):
        return 0
    else:
        return -1

money = 0
numberOfGames = 10**6
for i in range(numberOfGames):
    tmp = playGame(16, 17)
    money+= tmp
    # print(tmp)
    # print("-"*10)

    # if i % 10000 == 0:
        # print(numberOfGames)
print(money)