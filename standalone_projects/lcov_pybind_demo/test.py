import lib as m


def test_main():
    assert m.add(1, 2) == 3
    assert m.sub(1, 2) == -1
    # skip mul()
    # assert m.mul(4, 2) == 8


if __name__ == "__main__":
    test_main()
