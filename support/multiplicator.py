from random import randint

input_words = open('./words_alpha.txt')
output_text = open('./input.txt', 'a')

for word in input_words:
    data = word.replace('\n', '')
    text = " ".join([data for _ in range(randint(60, 80))])
    # text = data
    output_text.write(text)
    output_text.write(' ')

input_words.close()
output_text.close()
