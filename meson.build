project(
        'quality_control',
        'cpp',
        version: '0.0.1', 
        default_options : [
            'warning_level=3',
            'cpp_std=c++17'
        ]
)

quality_control_includes = include_directories('.')
quality_control_sources = ['quality_control/quality_control.cpp']
quality_control_deps = [dependency('logger', fallback: ['logger', 'logger_dep'])]
   
arg = ''
if get_option('buildtype').startswith('debug')
   arg = '-DDEBUG'
endif


add_project_arguments(arg, language: 'cpp')

quality_control = shared_library(
    'quality_control',
    quality_control_sources,
    include_directories : quality_control_includes,
    dependencies: quality_control_deps,
)


quality_control_dep = declare_dependency(include_directories: quality_control_includes, link_with: quality_control)

subdir('tests')