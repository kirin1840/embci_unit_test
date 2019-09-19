def targetBranch = "master"
node {
      stage("checkout git") {
      dir("${WORKSPACE}") {
          git url: "${gitUrl}", branch: "${targetBranch}"
          sh "ls -la"
      }
    }
}
