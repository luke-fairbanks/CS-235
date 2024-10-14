import json
from byu_pytest_utils import cache, compile_cpp, format_results_for_gradescope, run_exec, test_files, this_folder


@cache
def calculator_bin():
    return compile_cpp(this_folder / 'calculator.cpp')


@cache
def reformat_bin():
    return compile_cpp(this_folder / 'reformat.cpp')


@cache
def longest_line_bin():
    return compile_cpp(this_folder / 'longest_line.cpp')


test_results = {
    'calculator': [
        {
            'name': 'add',
            'points': 5,
            'result': run_exec(
                calculator_bin,
                expected_stdio=test_files / 'calc_add.dialog.txt',
            )
        },
        {
            'name': 'divide',
            'points': 5,
            'result': run_exec(
                calculator_bin,
                expected_stdio=test_files / 'calc_divide.dialog.txt',
            )
        },
        {
            'name': 'invalid_operation',
            'points': 5,
            'result': run_exec(
                calculator_bin,
                expected_stdio=test_files / 'calc_invalid_operation.dialog.txt',
            )
        },
        {
            'name': 'multiply',
            'points': 5,
            'result': run_exec(
                calculator_bin,
                expected_stdio=test_files / 'calc_multiply.dialog.txt',
            )
        },
        {
            'name': 'subtract',
            'points': 5,
            'result': run_exec(
                calculator_bin,
                expected_stdio=test_files / 'calc_subtract.dialog.txt',
            )
        },
        {
            'name': 'mod',
            'points': 5,
            'result': run_exec(
                calculator_bin,
                expected_stdio=test_files / 'calc_mod.dialog.txt',
            )
        }
    ],
    'reformat': [
        {
            'name': 'test1',
            'points': 17.5,
            'result': run_exec(
                reformat_bin,
                test_files / 'reformat_test1.input.txt', out := 'reformat_test1.output.txt',
                expected_files=[
                    (test_files / 'reformat_test1.output.txt', out)
                ]
            )
        },
        {
            'name': 'test2',
            'points': 17.5,
            'result': run_exec(
                reformat_bin,
                test_files / 'reformat_test2.input.txt', out := 'reformat_test2.output.txt',
                expected_files=[
                    (test_files / 'reformat_test2.output.txt', out)
                ]
            )
        }
    ],
    'longest_line': [
        {
            'name': 'test1',
            'points': 17.5,
            'result': run_exec(
                longest_line_bin, test_files / 'longest_line_test1.input.txt',
                expected_stdio=test_files / 'longest_line_test1.stdout.txt'
            )
        },
        {
            'name': 'test2',
            'points': 17.5,
            'result': run_exec(
                longest_line_bin, test_files / 'longest_line_test2.input.txt',
                expected_stdio=test_files / 'longest_line_test2.stdout.txt'
            )
        }
    ]
}

print(json.dumps(test_results, indent=2))

results = format_results_for_gradescope(test_results)

with open('results.json', 'w') as file:
    json.dump(results, file, indent=2)
