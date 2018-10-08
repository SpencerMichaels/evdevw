# This (very messy, one-off) script converts a list of #defines into a
# camel-case enum class with accompanying functions to convert to and from the
# raw values.
#
# Usage: enum_converter.py <defines_file> <enum_class_name>
#
# Each line of defines file should be formatted as follows; this is how
#   libevdev does it.
#
#   #define ENUM_NAME <one or more tabs> 0x1

import sys

def underscore_to_camelcase(value):
    def camelcase(): 
        yield str.lower
        while True:
            yield str.capitalize

    c = camelcase()
    return "".join(c.next()(x) if x else '_' for x in value.split("_"))

ENUM_CLASS = sys.argv[2]
f = open(sys.argv[1])
lines = f.readlines()

convert0 = []
lines2 = []
lines3 = []

for line in lines[:-2]:
  name = line.split(' ')[1].split('\t')[0]
  lines2.append(name)

line = lines[-2]
max_name = line.split(' ')[1].split('\t')[0]

for line in lines2:
  s = line.strip()
  lowered = s.lower()
  #i = lowered.find('_')
  #s2 = underscore_to_camelcase(lowered[(i+1):])
  s2 = underscore_to_camelcase(lowered)
  lines3.append(s + '\t' + s2[0].upper() + s2[1:])

for line in lines3:
  spl = line.strip().split('\t')
  key_code = spl[0]
  key_enum = spl[1]

  convert0.append(key_enum + ' = ' + key_code + ',')

print 'enum class ' + ENUM_CLASS + ' {'

for line in convert0:
  print '  ' + line

print '};'

print
print 'template <>'
print 'int enum_to_raw<int, ' + ENUM_CLASS + '>(' + ENUM_CLASS + ' code) {'
print '  using UT = std::underlying_type_t<'+ENUM_CLASS+'>;'
print '  return static_cast<UT>(code);'
print '}'

print
print 'template <>'
print ENUM_CLASS + ' raw_to_enum<' + ENUM_CLASS + ', int>(int code) {'
print '  if (code < '+max_name+')'
print '    throw std::runtime_error("Invalid value for enum type!");'
print '  return static_cast<'+ENUM_CLASS+'>(code);'
print '}'
