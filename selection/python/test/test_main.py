import pytest
from pytest_benchmark.fixture import BenchmarkFixture

from library.main import sum


def test_sum_positive_integers() -> None:
    assert sum(1, 2) == 3


def test_sum_negative_integers() -> None:
    assert sum(-1, -2) == -3


def test_sum_positive_and_negative() -> None:
    assert sum(5, -3) == 2


def test_sum_zero_and_positive() -> None:
    assert sum(0, 5) == 5


def test_sum_zero_and_negative() -> None:
    assert sum(0, -5) == -5


def test_sum_two_zeros() -> None:
    assert sum(0, 0) == 0


def test_sum_floats() -> None:
    assert sum(1.5, 2.5) == 4.0


def test_sum_integer_and_float() -> None:
    assert sum(1, 2.5) == 3.5


def test_sum_float_and_integer() -> None:
    assert sum(2.5, 1) == 3.5


def test_sum_large_positive_integers() -> None:
    assert sum(10**18, 10**18) == 2 * 10**18


def test_sum_large_negative_integers() -> None:
    assert sum(-(10**18), -(10**18)) == -2 * 10**18


def test_sum_string_concatenation() -> None:
    assert sum("hello", "world") == "helloworld"


def test_sum_empty_strings() -> None:
    assert sum("", "") == ""


def test_sum_list_concatenation() -> None:
    assert sum([1, 2], [3, 4]) == [1, 2, 3, 4]


def test_sum_empty_lists() -> None:
    assert sum([], []) == []


def test_sum_tuple_concatenation() -> None:
    assert sum((1, 2), (3, 4)) == (1, 2, 3, 4)


def test_sum_booleans() -> None:
    assert sum(True, True) == 2


def test_sum_true_false() -> None:
    assert sum(True, False) == 1


def test_sum_false_false() -> None:
    assert sum(False, False) == 0


def test_sum_identity_left() -> None:
    value = 12345
    assert sum(0, value) == value


def test_sum_identity_right() -> None:
    value = 12345
    assert sum(value, 0) == value


def test_sum_commutative_integers() -> None:
    assert sum(7, 11) == sum(11, 7)


def test_sum_commutative_floats() -> None:
    assert sum(1.25, 9.75) == sum(9.75, 1.25)


def test_sum_none_and_integer_raises() -> None:
    with pytest.raises(TypeError):
        sum(None, 1)


def test_sum_integer_and_none_raises() -> None:
    with pytest.raises(TypeError):
        sum(1, None)


def test_sum_string_and_integer_raises() -> None:
    with pytest.raises(TypeError):
        sum("1", 1)


def test_sum_integer_and_string_raises() -> None:
    with pytest.raises(TypeError):
        sum(1, "1")


def test_sum_list_and_tuple_raises() -> None:
    with pytest.raises(TypeError):
        sum([1], (2,))


@pytest.mark.parametrize(
    ("x", "y", "expected"),
    [
        (1, 2, 3),
        (-1, -2, -3),
        (5, -3, 2),
        (0, 5, 5),
        (0, 0, 0),
        (1.5, 2.5, 4.0),
        (1, 2.5, 3.5),
        (True, True, 2),
        ("a", "b", "ab"),
        ([1], [2], [1, 2]),
        ((1,), (2,), (1, 2)),
    ],
)
def test_sum_valid_cases(x: object, y: object, expected: object) -> None:
    assert sum(x, y) == expected


@pytest.mark.parametrize(
    ("x", "y"),
    [
        (None, 1),
        (1, None),
        ("1", 1),
        (1, "1"),
        ([1], (2,)),
    ],
)
def test_sum_invalid_cases(x: object, y: object) -> None:
    with pytest.raises(TypeError):
        sum(x, y)


def test_sum_benchmark(benchmark: BenchmarkFixture) -> None:
    benchmark(sum, 1, 2)
