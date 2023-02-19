import turtle

def draw(image, length):
    if length > 0:
        image.forward(length)
        image.left(90)
        draw(image, length - 10)


def main():
    image = turtle.Turtle()
    screen = turtle.Screen()

    colors = (
        '#006699',
        '#006666',
        '#660066',
        '#990000',
        '#ad3270',
        '#e65100',
        '#1a237e',
        '#827717',
        '#006064',
        '#f57f17',
        '#d50000',
        '#4a148c',
    )

    for color in colors:
        image.pencolor(color)
        draw(image, 100)

    screen.exitonclick()


if __name__ == '__main__':
    main()