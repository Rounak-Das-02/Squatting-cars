<template>
  <div class="home">
    <VideoView msg="Welcome to Your Vue.js App"/>
  </div>
</template>

<script>
// @ is an alias to /src
import VideoView from '@/components/VideoView.vue'

export default {
  name: 'HomeView',
  components: {
    VideoView
  }
}
</script>
