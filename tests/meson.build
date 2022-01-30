base_dep = [dependency('logger', fallback: ['logger', 'logger_dep'])]
base_includes = [quality_control_includes]
base_link = [
    shared_library('utils', 'utils.cpp', include_directories: include_directories('.'))
]

qc_equality_test = executable('qc_test',
                      'qc_equality_test.cpp',
                      include_directories: base_includes,
                      dependencies: base_dep,
                      link_with: base_link

)




test('Running quality_control test equality', qc_equality_test, is_parallel: true)
