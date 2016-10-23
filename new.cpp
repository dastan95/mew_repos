def get_path(vertices)
  result = Array.new
  tmp = Array.new(vertices)
  i = 0
  
  for j in 0...tmp.size
     tmp[j][0]=-1
  end
  
  result.push(1);
  
  while result.size<tmp.size
    b = tmp[i].find_index(tmp[i].min_by { |obj| obj>0 ? obj : 99999  })
    for j in 0...tmp[i].size
      tmp[j][b]=-1
    end
    result.push(b+1)
    i=b
  end
  return result
end

def show_vertices_matrix(arr)
  for i in 0...arr.size
     puts arr[i].to_s
  end
end

puts "Input number of vertices"
n = gets.to_i
a = Array.new(n) { |index| index=Array.new(n){|i| i=0} }
puts "Input the vertices"
for i in 0...a.size
  for j in 0...a[i].size
    if i<j 
      puts "Input distance from vertex #{i+1} to vertex #{j+1}"
      a[i][j]=gets.to_i
    else 
      if i==j
      a[i][j]=-1
      else
      a[i][j]=a[j][i]
      end  
    end   
  end
end
puts "Resulting matrix of vertices"
show_vertices_matrix(a)
puts "Shortest path starting from vertex 1 :"
puts get_path(a).to_s
 
