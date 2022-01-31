base_dep = [dependency('logger', fallback: ['logger', 'logger_dep']), dependency('UnitTest++')]
base_includes = [quality_control_includes]


qc_equality_test = executable('qc_equality_test',
                      ['quality_control/qc_equality_test.cpp'],
                      include_directories: base_includes,
                      dependencies: base_dep,
)

global_equality_test = executable('global_equality_test',
                      ['global/global_equality_test.cpp'],
                      include_directories: base_includes,
                      dependencies: base_dep,
)

test('Running quality_control (n) test equality', qc_equality_test, is_parallel: true)
test('Running quality_control (g) test equality', global_equality_test, is_parallel: true)

