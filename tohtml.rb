source_code = Dir["*.cpp"] + Dir["*.h"] + Dir["*.html"] + Dir["*.css"] + Dir["*.php"] + Dir["*.pl"]

puts "<!DOCTYPE html><html><body>"

def print_file(filename)
  puts "<h2>#{filename}</h2>"
  puts "<pre style='font:Monaco; font-size: 10pt'>"
  puts File.read(filename).gsub("&", "&amp;").gsub("<","&lt;").gsub(">","&gt;").gsub("\"", "&quot;").gsub("\n", "<br>").gsub("\r", "")
  puts "</pre>"
end

strip_extensions = lambda do |s|
  s.gsub(/\.cpp/,'').gsub(/\.h/,'')
end

order = ARGV.map(&strip_extensions)

source_code.map(&strip_extensions).uniq.sort{|a,b| 
  ai = order.index(a) || order.size
  bi = order.index(b) || order.size
  result = ai <=> bi
#  result = (a<=>b) if result==0
}.each do |filename|
  if File.exists?(filename+".h")
    print_file(filename+".h")
  end
  if File.exists?(filename+".cpp")
    print_file(filename+".cpp")
  end
end

puts "</body></html>"
