from base import Base


if __name__ == "__main__":
    print("Program is working!")
    for p in Base.plugins:
        # print(p)
        inst = p()
        inst.start()
