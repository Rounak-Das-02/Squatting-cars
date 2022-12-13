<template>
  <div class="home">
    <VideoView />
    {{ msg.count }}: {{ msg.rep }}
  </div>
</template>

<script>
// @ is an alias to /src
import VideoView from "@/components/VideoView.vue";
import axios from "axios";

export default {
  name: "HomeView",
  data() {
    return {
      msg: "",
      polling: null,
    };
  },
  components: {
    VideoView,
  },
  methods: {
    getMessage() {
      const path = "http://localhost:5000";
      axios
        .get(path)
        .then((res) => {
          this.msg = res.data;
        })
        .catch((error) => {
          console.error(error);
        });
    },
    pollData() {
      this.polling = setInterval(() => {
        this.getMessage();
      }, 1);
    },
  },
  created() {
    this.pollData();
  },
  beforeDestroy() {
    clearInterval(this.polling);
  },
};
</script>
