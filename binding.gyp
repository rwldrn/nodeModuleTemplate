{
  # 'variables' : {
  #   'source_files': '<!@(["find ./ -name *.cc"])'
  # },
  'targets': [  
    {
      'target_name': 'moduleName',
      # 'type': '<(library)',
      'sources': [ 
        # '<@(source_files)'
        './src/moduleName.cc'         
      ],
      'cflags!': [
        '-03',
        '-Wall',
        '-Wno-eof-newline',
        '-msse2',
        '-fno-exceptions'
      ],
      'cflags_cc!': [
        '-03',
        '-Wall',
        '-Wno-eof-newline',
        '-msse2',
        '-fno-exceptions'
      ],      
      'defines': [
        '_FILE_OFFSET_BITS=64',
        '_LARGEFILE_SOURCE',
        '_MODULE_NAME_NODE_MODULE'
      ],
      'include_dirs+': [
        'src/'
      ],
      'link_settings': {
        'conditions' : [
            ['OS=="linux"',
                {
                    'libraries': [
                    ]
                }
            ],
            ['OS=="mac"',
                {
                    'libraries': [
                    ]
                }
            ]
        ]
      }  
    }
  ]
}