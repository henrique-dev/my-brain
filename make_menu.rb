if (ARGV[1] && path = ARGV[0])
  file_menu = File.new("#{ARGV[1]}", 'w')

  File.open(path, 'r') do |f|
    lines = f.each_line.to_a
    lines.each do |line|
      if line[0] == '#'
        title_with_mark = line.split(' ')
        mark = title_with_mark[0]
        if mark.match?(/^[#]+$/)
          title_with_mark.shift
          title = title_with_mark.join(' ')
          file_menu.puts "#{' ' * ((mark.length-1) * 2)}- [#{title}](#{ARGV[1]}##{title.downcase.gsub!(' ', '-')})"
        end
      end
    end
  end

  file_menu.close
end
