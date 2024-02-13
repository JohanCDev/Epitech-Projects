#!/usr/bin/env python3
import process
import groundhog
import calculation
import pytest


def test_end_prog_failure():
    with pytest.raises(SystemExit) as pytest_wrapped_e:
        process.end_prog([], 2, 9, 7)
    assert pytest_wrapped_e.type == SystemExit
    assert pytest_wrapped_e.value.code == 84


def test_end_prog_success(capsys):
    ret = process.end_prog([], 2, 5, 7)
    captured = capsys.readouterr()
    assert captured.out == "Global tendency switched 2 times\n0 weird values are []\n"
    assert ret == 0


def test_printing_res(capsys):
    ret = process.print_res(3, 4, 2, 1)
    captured = capsys.readouterr()
    message = "g=3.00\t\tr=4%\t\ts=2.00\n"
    assert captured.out == message
    assert ret == 0


def test_printing_res_with_switch(capsys):
    ret = process.print_res(3, 4, 2, -1)
    captured = capsys.readouterr()
    message = "g=3.00\t\tr=4%\t\ts=2.00\t\ta switch occurs\n"
    assert captured.out == message
    assert ret == 1


def test_printing_res_with_nan(capsys):
    ret = process.print_res("nan", "nan", "nan", "nan")
    captured = capsys.readouterr()
    message = "g=nan\t\tr=nan%\t\ts=nan\n"
    assert captured.out == message
    assert ret == 0


def test_helper(capsys):
    groundhog.print_helper()
    captured = capsys.readouterr()
    message = "SYNOPSIS\n\t./groundhog period\n\nDESCRIPTION\n\tperiod\tthe number of days defining a period\n"
    assert captured.out == message


def test_main_with_h():
    ret = groundhog.main(2, ["./groundhog", "-h"])
    assert ret == 0


def test_main_with_invalid_arg():
    ret = groundhog.main(2, ["./groundhog", "A"])
    ret2 = groundhog.main(3, ["./groundhog", "-h", "az"])
    ret3 = groundhog.main(1, ["./groundhog"])
    assert ret == 84
    assert ret2 == 84
    assert ret3 == 84


def test_invalid_calcs():
    rret = calculation.r([2, 4, 3], 5)
    rret2 = calculation.r([2, 4, 3], 3)
    sret = calculation.s([2, 4, 3], 6)
    gret = calculation.g([2, 4, 3], 6)
    gret2 = calculation.g([2, 4, 3], 3)
    assert rret == "nan"
    assert rret2 == "nan"
    assert sret == "nan"
    assert gret == "nan"
    assert gret2 == "nan"


def test_calculation_g():
    assert calculation.g([2, 5, 2, 3, 6, 11], 2) == 4


def test_calculation_r():
    assert calculation.r([2, 1, 4, 3, 2], 2) == -50


def test_calculation_s():
    assert calculation.s([2, 1, 4, 3, 2], 2) == 0.5

