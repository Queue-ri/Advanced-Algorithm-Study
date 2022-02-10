# 22-02-10
# Comment PR by Queue-ri

require "octokit"

if ARGV.length < 3
  puts "ERROR: Missing arguments."
  exit(1)
end

repo = "Queue-ri/Advanced-Algorithm-Study"

github = Octokit::Client.new(access_token: ARGV[0])
pr_number = ARGV[1]
file_path = ARGV[2]

message = File.read(file_path)
coms = github.issue_comments(repo, pr_number)

github.add_comment(repo, pr_number, message)